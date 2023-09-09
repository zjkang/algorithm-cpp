// hash set
// https://en.cppreference.com/w/cpp/container/unordered_set
template<
    class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
>
class unordered_set;

#include <iostream>
#include <unordered_set>
 
void print(const auto& set)
{
    for (const auto& elem : set)
        std::cout << elem << ' ';
    std::cout << '\n';
}

unordered_set<int> s;
s.size(); s.empty();
s.count(1);
s.insert(1);
s.erase(1);

 
#include <iostream>
#include <unordered_set>
 
void print(const auto& set)
{
    for (const auto& elem : set)
        std::cout << elem << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::unordered_set<int> mySet{2, 7, 1, 8, 2, 8}; // creates a set of ints
    print(mySet);
 
    mySet.insert(5); // puts an element 5 in the set
    print(mySet);
 
    if (auto iter = mySet.find(5); iter != mySet.end())
        mySet.erase(iter); // removes an element pointed to by iter
    print(mySet);
 
    mySet.erase(7); // removes an element 7
    print(mySet);
}


// Custom Hash Functions for C++ Unordered Containers
// https://ianyepan.github.io/posts/cpp-custom-hash/

// p is a pair<string, int>
hash<string>{}(p.first) ^ hash<int>{}(p.second); // simple and effective

class Example {
 public:
  void func() {
    auto pairHash = []<typename T1, typename T2>(const pair<T1, T2> &p) {
      return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
    };
    unordered_set<pair<int, int>, decltype(pairHash)> seen(10, pairHash);
    unordered_map<pair<double, string>, int , decltype(pairHash)> umap(10, pairHash);
  }
};


std::ostream& operator<< (std::ostream& os, std::unordered_set<int> const& s) {
  for (os << "[" << s.size() << "] { "; int i : s)
    os << i << ' ';
  return os << "}\n";
}

std::unordered_set<int> nums = {2, 3, 4};
auto p = nums.insert (1); // insert element


// -------------------------------------------------------------
// set
// https://en.cppreference.com/w/cpp/container/set
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;

set<int> s;
s.empty(); s.size();
s.count(1); s.find(1);
s.insert(1);
s.lower_bound(1); s.upper_bound(1);


// https://usaco.guide/silver/custom-cpp-stl?lang=cpp
// C++ Sets with Custom Comparators

set<int, greater<int>> a;
map<int, string, greater<int>> b;
priority_queue<int, vector<int>, greater<int>> c;

// Operator Overloading
#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) const { return w < y.w; }
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


// With a function
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


// lambda function
auto cmp = [](const Edge &x, const Edge &y) { return x.w < y.w; };
int main() {
	int M = 4;
	set<Edge, bool (*)(const Edge &, const Edge &)> v(cmp); // set<Edge,decltype(cmp)> v(cmp);
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
// even though decltype(cmp) is not actually equivalent to bool(*)(const Edge&,const Edge&). See Lambda Expressions for details.


// Functors
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


// Built-In Functors
#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int a, b, w;
	bool operator>(const Edge &y) const { return w > y.w; }
};
int main() {
	int M = 4;
	set<Edge, greater<Edge>> v;
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




