// hash map

// https://cplusplus.com/reference/unordered_map/unordered_map/

// default value to empty vector<stinrg>
unordered_map<string,vector<string>> map1; 
// default value to 0
unordered_map<string, int> map2; 

// key -> a.first, value -> a.second
for (auto a : map1) { 
  results.push_back(a.second);
}

map1["a"] = {"1","2"};
if (map1.find("a")!=map1.end()) {
}
map1.count("a");


// ----------------------------------------------------------
// tree map

// https://en.cppreference.com/w/cpp/container/map
// https://en.cppreference.com/w/cpp/container/map/lower_bound

map<int, int> map;
auto lower_iter = map.lower_bound(1);

// https://www.techiedelight.com/use-std-pair-key-std-map-cpp/
// when pair is used as key
// 1. Using default order


// 2. Using a comparison object

// 3. Specializing std::less function





// ---------------------------------------------
