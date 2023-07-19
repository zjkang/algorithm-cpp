# C++ data structure

Include most frequent c++ usage with modern principles for leetcode algorithm

```c++
// null pointer
int* a = NULL; // or prefer to use 
int* b = nullptr;
```

```c++
// long name type usage
typedef long long LL;
typedef pair<LL, LL> PLL;
LL a = 0;
```

```c++
// apply lambda function (https://en.cppreference.com/w/cpp/language/lambda)
// format: [captures](parameters) {body}
// e.g.,
static bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
// < == >
[](auto& a, auto& b) { return a[1] < b[1]; }
```

```c++
 // pair<> type
 pair<int, int> pair = make_pair(1, 2);
```

 
### Stream

```c++
ostringstream oss("");
istringstream iss("16.5 ounces");
double amount;
string unit;
iss >> amount >> unit;
```

- stream state bit

```
// state bits
```


### Iterator

- https://cplusplus.com/reference/iterator/

Input (Read)    <-- Forward   <-- Bidirectional  <-- Random Access

Output (Write)

```c++
// begin, end, prev, next, back_inserter
int foo[] = {10,20,30,40,50};
std::vector<int> bar;
// iterate foo: inserting into bar
for (auto it = std::begin(foo); it!=std::end(foo); ++it) {
    bar.push_back(*it);
}
```


### binary search 

- lower_bound / upper_bound support comp
- https://en.cppreference.com/w/cpp/algorithm/lower_bound

```c++
// template< class ForwardIt, class T, class Compare >
// ForwardIt lower_bound(
//     ForwardIt first, ForwardIt last, const T& value, Compare comp );
// 
vector<int> packages;
int val = 10;
auto iterLower = lower_bound(packages.begin(), packages.end(), val); // the first iterator >= val
auto iterUpper = upper_bound(packages.begin(), packages.end(), val)); // the first iterator > val
int offsetLower = prev(iter) - packages.begin();
```


### vector 
- https://cplusplus.com/reference/vector/vector/

```c++
vector<vector<int>> events;
sort(events.begin(), events.end(), [](auto &a, auto& b) { return a[1] < b[1]; }); // sorting by index 1
events.insert(events.begin(), events[0]); // insert
events.push_back(); 
events.pop_back();
events.size();
events.empty();
```

```c++
// https://en.cppreference.com/w/cpp/container/vector/emplace_back
// no need to create a temporary copy constructor as in push_back
// Person(string name, int age);
person = Person("abc", 10);
events.push_back(Person("abc", 10));
// < == >
events.emplace_back("abc", 10);
```

```c++
// p1
vector<int> vec = {1,2,3};
int sum = 0;
for (auto val : vec) {
  sum += val;
}
// p2 (reference)
vector<int> vec = {1,2,3};
int sum = 0;
for (const auto& val : vec) {
  sum += val;
}
// p3 (stl)
vector<int> vec = {1,2,3};
int sum = std:accumulate(vec.begin(), vec.end(), 0);
```

```c++
// 2d vector
int rows = 10, cols = 5;
vector<vector<int>> dimens(rows, vector<int>(cols, val));
```


### priority queue 

- https://en.cppreference.com/w/cpp/container/priority_queue

```c++
// defalt to max priority heap
// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class priority_queue;
const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
print("data", data);
std::priority_queue<int> q1; // Max priority queue
for (int n : data) {
    q1.push(n);
}
```

```c++
// Min priority queue
// std::greater<int> makes the max priority queue act as a min priority queue
std::priority_queue<int, std::vector<int>, std::greater<int>> minq1(data.begin(), data.end());
// Second way to define a min priority queue
std::priority_queue minq2(data.begin(), data.end(), std::greater<int>());
```

```c++
// Using a custom function object to compare elements.
struct
{
    bool operator()(const int l, const int r) const { return l > r; }
} customLess;
std::priority_queue minq3(data.begin(), data.end(), customLess); // Min priority queue

```c++
// Using lambda to compare elements.
auto cmp = [](int left, int right) { return left < right; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp); // Max priority queue
for (int n : data) {
    q5.push(n);
}

// result
// data:   1 8 5 6 3 4 0 9 7 2
// q1:     9 8 7 6 5 4 3 2 1 0
// minq1:  0 1 2 3 4 5 6 7 8 9
// minq2:  0 1 2 3 4 5 6 7 8 9
// minq3:  0 1 2 3 4 5 6 7 8 9
// q5:     9 8 7 6 5 4 3 2 1 0
```

```c++
// APIs
pq.top(), pq.empty(), pq.size(), pq.push(), pq.pop()
```


### stack

```c++
stack<int> s;
s.push(1);
s.top();
s.pop();
s.empty();
```


### queue 
- https://en.cppreference.com/w/cpp/container/queue

```c++
queue<int> q;
q.front(); 
q.push(u);
q.pop();
```


### deque 
- https://cplusplus.com/reference/deque/deque/

```c++
deque<int>q;
q.front(); q.back();
q.push_front(); q.push_back();
q.pop_front(); q.pop_back();
```







### hash map

- https://cplusplus.com/reference/unordered_map/unordered_map/

```c++
unordered_map<string,vector<string>> map1; // default value to empty vector<stinrg>?
unordered_map<string, int> map2; // default value to 0

// key -> a.first, value -> a.second
for (auto a : map1) { 
  results.push_back(a.second);
}

map1["a"] = {"1","2"};
if (map1.find("a")!=map1.end()) {
}

map1.count("a");
```


### tree map



// -----------------------------------------------------------
// set

// algorithm & function









