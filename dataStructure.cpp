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
unordered_map<string,vector<string>> map1; // default value to empty vector<stinrg>?
for (auto a : map1) { // key -> a.first, value -> a.second
  results.push_back(a.second);
}
unordered_map<string, int> map2; // default value to 0?

// set

// sorting

// algorithm & function
// binary_search









