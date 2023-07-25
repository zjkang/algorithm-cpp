// hash set
// https://en.cppreference.com/w/cpp/container/unordered_set


std::ostream& operator<< (std::ostream& os, std::unordered_set<int> const& s) {
  for (os << "[" << s.size() << "] { "; int i : s)
    os << i << ' ';
  return os << "}\n";
}

std::unordered_set<int> nums = {2, 3, 4};
auto p = nums.insert (1); // insert element
