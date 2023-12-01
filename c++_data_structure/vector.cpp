https://cplusplus.com/reference/vector/vector/
https://en.cppreference.com/w/cpp/container/vector

vector<int> v{1,3,2,4,5}; // uniform initialization
sort(v.begin(), v.end()); // sort in ascending order
sort(v.begin(), v.end(), greater<int>()); // sort in descending order
sort(v.rbegin(), v.rend()); // sort in descending order as it considers the last element (rbegin()) in the vector as the first element in order,
// and then order by ascending from the last to the first.

vector<vector<int>> events;
bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
sort(events.begin(), events.end(), cmp);
// differentiate type & object
// cmp is function object (function pointer)
// decltype(cmp) is type or bool(*)(vector<int>&, vector<int>&b) is type

// lambda function: sorting by index 1
auto cmp = [](auto &a, auto& b) { return a[1] < b[1]; };
sort(events.begin(), events.end(), cmp);

// greater<int> is type, greater<int>() is a operator function
vector<int> points;
sort(points.begin(), points.end(), greater<int>()); // sort by descending order

// basic apis
events.insert(events.begin(), events[0]); // insert
events.push_back();
events.pop_back();
events.size();
events.empty();


// code snippet
#include <iostream>
#include <vector>

int main()
{
    // Create a vector containing integers
    std::vector<int> v = {8, 4, 5, 9};

    // Add two more integers to vector
    v.push_back(6);
    v.push_back(9);

    // Overwrite element at position 2
    v[2] = -1;

    // Print out the vector
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}

// push_back vs emplace_back
// https://en.cppreference.com/w/cpp/container/vector/emplace_back
// no need to create a temporary copy constructor as in push_back
// Person(string name, int age);
Person person = Person("abc", 10);
events.push_back(Person("abc", 10));
// < == >
events.emplace_back("abc", 10);

// for loop via auto
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


// 2d vector
int rows = 10, cols = 5;
vector<vector<int>> dimens(rows, vector<int>(cols, val));
// 3d vector: can remove internal vector representation
vector<vector<vector<double>>>
vector dp(k + 1, vector(n, vector<double>(n, 0.0)));


// need to delete element while iterating
// using it = a.erase(it);
vector<int> a{1,2,3,4,5,1,2};
for (auto it = a.begin(); it != a.end();) {
  if (*it == 2) {
    it = a.erase(it); // the previous it iterator is invalidated
  } else {
    it++;
  }
}
for (auto x : a) cout << x << endl;

