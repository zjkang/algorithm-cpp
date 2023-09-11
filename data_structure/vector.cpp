https://cplusplus.com/reference/vector/vector/

vector<vector<int>> events;

// differentiate type & object
// cmp is function object (function pointer) 
// decltype(cmp) is type or bool(*)(vector<int>&, vector<int>&b) is type
static bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
sort(events.begin(), events.end(), cmp);
// sorting by index 1
sort(events.begin(), events.end(), [](auto &a, auto& b) { return a[1] < b[1]; }); 

vector<int> points;
// greater<int> is type, greater<int>() is a operator function
sort(points.begin(0, points.end(), greater<int>()); // sort by desc order

events.insert(events.begin(), events[0]); // insert
events.push_back(); 
events.pop_back();
events.size();
events.empty();

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

