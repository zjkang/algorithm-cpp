// long name type usage
typedef long long ll;
ll a = 0;

// apply lambda function
// https://en.cppreference.com/w/cpp/language/lambda
// [captures](parameters) {body} e.g.,
static bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
// < == >
[](auto& a, auto& b) { return a[1] < b[1]; }



// ----------------------------------------------
// binary search
// https://en.cppreference.com/w/cpp/algorithm/lower_bound
// lower_bound / upper_bound support comp as well
//
// template< class ForwardIt, class T, class Compare >
// ForwardIt lower_bound(
//     ForwardIt first, ForwardIt last, const T& value, Compare comp );
vector<int> packages;
int val = 10;
auto iterLower = lower_bound(packages.begin(), packages.end(), val); // the first iterator >= val
auto iterUpper = upper_bound(packages.begin(), packages.end(), val)); // the first iterator > val
int offsetLower = prev(iter) - packages.begin();


// ----------------------------------------------
// vector
vector<vector<int>> events;
sort(events.begin(), events.end(), [](auto &a, auto& b) { return a[1] < b[1]; }); // sorting by index 1
events.insert(events.begin(), events[0]); // insert
events.push_back();
events.size();
events.empty();

// https://en.cppreference.com/w/cpp/container/vector/emplace_back
// no need to create a temporary copy constructor as in push_back

// Person(string name, int age);
person = Person("abc", 10);
events.push_back(Person("abc", 10));
// < == >
events.emplace_back("abc", 10);





// c++ modern principles

// ----------------------------------------------
// stream
ostringstream oss("");
istringstream iss("16.5 ounces");
double amount;
string unit;
iss >> amount >> unit;

// state bits

// array

// vector
// p1
vector<int> vec = {1,2,3};
int sum = 0;
for (auto val : vec) {
  sum += val;
}
// p2
vector<int> vec = {1,2,3};
int sum = 0;
for (const auto& val : vec) {
  sum += val;
}
// p3
vector<int> vec = {1,2,3};
int sum = std:accumulate(vec.begin(), vec.end(), 0);




// list

// priority queue

// -----------------------------------------------------------
// hash map
// https://cplusplus.com/reference/unordered_map/unordered_map/
// APIs:
unordered_map<string,vector<string>> map1; // default value to empty vector<stinrg>?
unordered_map<string, int> map2; // default value to 0

for (auto a : map1) { // key -> a.first, value -> a.second
  results.push_back(a.second);
}
map1["a"] = {"1","2"};
if (map1.find("a")!=Map.end()) {
}






// -----------------------------------------------------------
// set

// sorting

// algorithm & function
// binary_search









