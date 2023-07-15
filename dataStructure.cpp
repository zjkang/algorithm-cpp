// long name type usage
typedef long long ll;
ll a = 0;


// ----------------------------------------------
// binary search
vector<int>& packages;
int val = 10;
auto iterLower = lower_bound(packages.begin(), packages.end(), val); // the first iterator >= val
auto iterUpper = upper_bound(packages.begin(), packages.end(), val)); // the first iterator > val
int offsetLower = prev(iter) - packages.begin();


// ----------------------------------------------
// binary search



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









