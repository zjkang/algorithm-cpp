// -------------------------------------------------------------
// set
// https://en.cppreference.com/w/cpp/container/set
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;

set<int> s;
s.empty();
s.size();
s.count(1); 
s.find(1) != s.end();
s.insert(1);
s.lower_bound(1); s.upper_bound(1);
it = s.erase(it); // after remove the value the iterator points to, returns the next iterator


// https://usaco.guide/silver/custom-cpp-stl?lang=cpp
// C++ Sets with Custom Comparators
set<int, greater<int>> a; // decreasing order
map<int, string, greater<int>> b; // decreasing order
priority_queue<int, vector<int>, greater<int>> c; // min-heap

#include <set>
int main() {
  std::set<int, std::greater<int>> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);

  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << std::endl;
  }
}
// print 3, 2, 1 


// 1. Operator Overloading
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, w;
  bool operator<(const Edge &y) const { return w < y.w; } // < overload
};
int main() {
  int M = 4;
  set<Edge> v;
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.insert({a, b, w});
  }
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}


// 2. With a function
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, w;
};
bool cmp(const Edge &x, const Edge &y) { return x.w < y.w; }
int main() {
  int M = 4;
  set<Edge, bool (*)(const Edge &, const Edge &)> v(cmp); // set<Edge,decltype(&cmp)> v(cmp);
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.insert({a, b, w});
  }
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}


// 3. lambda function
auto cmp = [](const Edge &x, const Edge &y) { return x.w < y.w; };
int main() {
  int M = 4;
  // set<Edge,decltype(cmp)> v(cmp);
  // set<Edge,decltype(cmp)> v; // also works
  set<Edge, bool (*)(const Edge &, const Edge &)> v(cmp); 
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.insert({a, b, w});
  }
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
// even though decltype(cmp) is not actually equivalent to bool(*)(const Edge&,const Edge&). 
// See Lambda Expressions for details.


// 4. Functors
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, w;
};
struct cmp {
  bool operator()(const Edge &x, const Edge &y) const { return x.w < y.w; }
};
int main() {
  int M = 4;
  set<Edge, cmp> v;
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.insert({a, b, w});
  }
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
// cmp like a normal function by adding () after it
int main() {
  int M = 4;
  vector<Edge> v;
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.push_back({a, b, w});
  }
  sort(begin(v), end(v), cmp());
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}


// 5. Built-In Functors less<T> or greater<T>
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, w;
  bool operator>(const Edge &y) const { return w > y.w; }
};
int main() {
  int M = 4;
  set<Edge, greater<Edge>> v; // decreasing order
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    v.insert({a, b, w});
  }
  for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
/* Output:
2 3 10
1 2 9
1 3 7
2 4 3
*/


// most convenient way: use
// array<int,2> or pair<int,int> or tuple<int, string, int,...> in the set
set<array<int,2>> set = {{1,2},{4,2}, {2,1}};
for (auto x : set) {
  cout << x[0] << "," << x[1] << endl;
}

tuple<int,string,int> a = {1,"abc", 2};
auto [a1,b1,c1]  = a;
std::tie(a1,b1,c2) = a;


// How to erase elements while iterating
set<int> set{1,2,3,4};
// erase elements while iterating
for (auto it = set.begin(); it != set.end();) {
    if (*it % 2 == 0) {
        it = set.erase(it); // it moves to the next iterator position
        cout << "next it: " << *it << endl;
    } else {
        it++;
    }
}
for (auto x : set) cout << x << endl;

// Note: it will fail in some c++ compiliers
for (auto it : set) {
    if (it % 2 == 0) {
        auto x = set.erase(it); // it moves to the next iterator position
        cout << "next x: " << x << endl;
    }
}
for (auto x : set) cout << x << endl;


