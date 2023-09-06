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


