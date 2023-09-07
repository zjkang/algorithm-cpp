// int to long long
int a; -> (long long) a;
// null pointer
int* a = NULL; // or prefer to use 
int* b = nullptr;


// long name type usage
typedef long long LL;
typedef pair<LL, LL> PLL;
LL a = 0;
// modern c++ 
using LL = long long;


// apply lambda function (https://en.cppreference.com/w/cpp/language/lambda)
// format: [captures](parameters) {body}
// e.g.,
static bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
// < == >
[](auto& a, auto& b) { return a[1] < b[1]; }


// pair<> type
pair<int, int> pair = make_pair(1, 2);
pair<int, int> pair = {1,2};


// modern c++
// initializer list (c++ 11)
// ex 1
vector<int> v{1,2,3,5}; // <==> initializer_list<int> l = {1,2,3,5}; vector<int> v(l);
vector<int> v = {1,2,3,5}; // assignment
vector<int> v{1,2,3,5}; // construction
// ex 2
vector<pair<int, float>> v{{1,2.5f}, {3,3.14f}};
// ex 3
map<string, int>> m{{"hello", 0}, {"world", 1}};

// uniform initialization
int x = 2; => int x(2); => int x{2};
pair<int, int> x(3,4); // constructor {3,4}
pair<int, int> x{3,4}; // {3,4}
vector<int> v(5,1); // v = [1,1,1,1,1]
vector<int> v{5,1}; // v = {5,1};

vector<int> foo() {
    set<int> ans = ...
    return vector<Mint>(begin(ans), end(ans));
    <==>
    return {begin(ans), end(ans)};
}


// auto keyword (c++ 11)
// ex3
auto v = vector<int>(10,1); // ok
vector<int> v(10,1); // better shorter
// ex4
auto v{1,2,3,4,5}; // doesn't compile
auto v = {1,2,3,4,5}; // v is NOT a vector, but a initializer list
// ex5: smart pointers
std::unique_ptr<Foo> p = std::make_unique<Foo>(...);
auto p = std::make_unique<Foo>(...);
// ex6:
set<int> s{1,2,3,4,5};
// before
typedef set<int>::iterator IT;
typedef set<int>::const_iterator CIT;
for (IT it = s.begin(); it != s.end(); ++it) ...
for (CIT it = s.cbegin(); it != s.cend(); ++it) ...
IT it = s.find(x);
// after
for (auto it = s.begin(); it != s.end(); ++it) ...
for (auto it = s.cbegin(); it != s.cend(); ++it) ...
auto it = s.find(x);


// structured binding (c++ 17)
pair<int, float> p{1,3.14};
const auto& [x,y] = p; // must be auto
// ex1
int a = 3, b = 4;
auto [x,y] = std::tie(a,b);
// python: x,y = a,b
<==>
int& x = a; int& y = b;
// ex2
set<int> s;
const auto [it, success] = s.insert(x);
// ex3
vector<pair<string, int>> v1{{"a", 1}, {"b", 2}};
auto [k,v] = v1[0]; // ok
vector<array<int, 3>> v2{{1,2,3}};
auto [a,b,c] = v2[0]; // ok
vector<vector<int>> v3{{1,2,3}};
auto [a,b,c] = v3[0]; // doesn't compile


// range based for loop (c++11)
set<int> s{1,2,3,4,5};
for (int x : s) foo(x)

map<string, int> m;
for (auto&& kv : m) {
    cout << kv.first << " " << kv.second << endl;
}
for (auto&& [key, va]: m) {
    cout << key << " " << val << endl;
}


// lambda expression (c++ 11)
// construct a closure: an unnamed function object capture variables in scope

// ex1: custom comparison function
// before
bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}
sort(begin(v), end(v), comp);
// after
sort(begin(v), end(v), [](const auto& a, const auto& b) {return a.second < b.second; });

// ex2: callback to access member function
// after
class Foo() {
public:
    void Init() {
    // capture this pointer
    bar_->onUpdate([this](const auto& data) {
        this->onUpdate(data); // can access members
    });
    }
private:
    Bar* bar_;
    void onUpdate(const vector<int>& data) { ... }
}

// ex4: capture
int a = 1;
auto foo = [a] { a += 1; };
foo();
ASSERT(a == 1);

int a = 1;
auto foo = [&a] { a += 1; };
foo();
ASSERT(a == 1);
// capture all variables by value / copy
auto foo = [=] { return a + b + c; }
// capture all by value except a by reference
auto foo = [=, &a] { a += b + c; }



