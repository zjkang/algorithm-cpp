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
s.size();
s.empty();
s.count(1);
s.insert(1);
s.find(1) != s.end();
s.erase(1); // size_type erase( const Key& key );
s.erase(iterator); // iterator erase( iterator pos );


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
// e.g.,
auto pairHash = []<typename T1, typename T2>(const pair<T1, T2> &p) {
  return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
};
unordered_set<pair<int, int>, decltype(pairHash)> seen(10, pairHash);
unordered_map<pair<double, string>, int , decltype(pairHash)> umap(10, pairHash);

seen.insert({1,2});
cout << seen.count({1,2}) << endl;

umap[{1.2, "abc"}] = 10;
cout << umap[{1.2, "abc"}] << endl;


std::ostream& operator<< (std::ostream& os, std::unordered_set<int> const& s) {
  os << "[" << s.size() << "] { "; 
  for (int i : s) os << i << ' ';
  return os << "}\n";
}

std::unordered_set<int> nums = {2, 3, 4};
cout << nums << endl;
auto p = nums.insert(1); // insert element

