- https://cplusplus.com/reference/vector/vector/

vector<vector<int>> events;

static bool cmp(vector<int>&a, vector<int>&b) {
    return a[1] < b[1];
}
sort(events.begin(), events.end(), cmp);
sort(events.begin(), events.end(), [](auto &a, auto& b) { return a[1] < b[1]; }); // sorting by index 1

events.insert(events.begin(), events[0]); // insert
events.push_back(); 
events.pop_back();
events.size();
events.empty();

vector<int> points;
sort(points.begin(0, points.end(), greater<int>()); // sort by desc order


// push_back vs emplace_back
// https://en.cppreference.com/w/cpp/container/vector/emplace_back
// no need to create a temporary copy constructor as in push_back
// Person(string name, int age);
person = Person("abc", 10);
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

