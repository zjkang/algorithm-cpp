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
// initializer list
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








