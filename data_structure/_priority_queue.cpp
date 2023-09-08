// https://en.cppreference.com/w/cpp/container/priority_queue

// defalt to max priority heap
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
at the expense of logarithmic insertion and extraction.

A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> would cause the smallest element 
to appear as the top().

vector<int> data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
print("data", data);
std::priority_queue<int> q1; // Max priority queue
for (int n : data) {
    q1.push(n);
}


// Min priority queue
// 1. std::greater<int> makes the max priority queue act as a min priority queue
std::priority_queue<int, std::vector<int>, std::greater<int>> minq1(data.begin(), data.end());

// 2. define a min priority queue
std::priority_queue minq2(data.begin(), data.end(), std::greater<int>());

// 3. Using a custom function object to compare elements.
struct {
    bool operator()(const int l, const int r) const { return l > r; }
} customLess;
std::priority_queue minq3(data.begin(), data.end(), customLess); 

// 4. Using a custom function object to compare elements.
struct CustomLess {
    bool operator()(const int l, const int r) const { return l > r; }
};
std::priority_queue<int, vector<int>, CustomLess> minq4(data.begin(), data.end());

// 5. Using lambda to compare elements.
auto cmp = [](int left, int right) { return left < right; };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp); // Max priority queue
for (int n : data) {
    q5.push(n);
}
// It also works after removing cmp in the constructor
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5;

// APIs
pq.top(); 
pq.empty(); 
pq.size();
pq.push();
pq.pop();


// constructs element <in-place> and sorts the underlying container
pq.emplace();

// e.g.
#include <iostream>
#include <queue>
 
struct S
{
    int id;
 
    S(int i, double d, std::string s) : id{i}
    {
        std::cout << "S::S(" << i << ", " << d << ", \"" << s << "\");\n";
    }
 
    friend bool operator< (S const& x, S const& y) { return x.id < y.id; }
};
 
int main()
{
    std::priority_queue<S> adaptor;
 
    adaptor.emplace(42, 3.14, "C++");
 
    std::cout << "id: " << adaptor.top().id << '\n';
}


// ----------------------------------------------

