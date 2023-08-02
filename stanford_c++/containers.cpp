// Overview of STL
// - Containers (include Adaptors)
// - Iterators
// - Functors
// - Algorithms


// -----------------------------------------
// Sequence Containers: sequences of elements
std::vector<T>
std::deque<T>
std::list<T>
std::array<T>
std::forward_list<T>

// standard C++ version
vector<int> v = {1, 3, 7};
v.push_back(271);
v.front();
v.back();
v.erase(v.begin());
v.pop_back();
// no such thing as a sublist

// loop
for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << endl;
}
for (string elem : v) {
    cout << elem << endl;
}

v.push_front(); // can be very slow due to moving the all the elements

v.at(i); // throws an exception
v[i];    // causes undefined behavior!


// note: vector outperforms a deque for element access. 
deque<int> d = {1, 3, 7};
d.push_back(271);
d.push_front(-1);
d.front();
d.back();


// -----------------------------------------
// adaptors
// stack & queue are container adaptors

template<
  class T,
  class Container = std::deque<T>
> class stack;
// provide functions: back(), push_back(), pop_back()

template<
  class T,
  class Container = std::deque<T>
> class queue;
// provide functions: back(), front(), push_back(), pop_front()


// -----------------------------------------
// associative containers

// map, set keys are comparable using < (less than) operator
std::map<T1, T2>
std::set<T> //  a set is just a specific case of a map that doesn't have a value
// unordered_map, unordered_set based on hash function
std::unordered_map<T1, T2>
std::unordered_set<T>

// https://en.cppreference.com/w/cpp/container/map
// mymap.at(key) vs mymap[key]
// mymap.count(key);
mymap.insert({2, 30}); // insert by initializer list


// -----------------------------------------
// iterators
// Remember: Assoc. containers have no notion of a sequence/indexsing

// Four essential iterator operations:
// Create iterator
// Dereference iterator to read value currently pointed to
// Advance iterator
// Compare against another iterator (especially .end() iterator)

// vector iterator
int numOccurrences(vector<int>& cont, int elemToCount) {
    int counter = 0;
    vector<int>::iterator iter;
    for(iter = cont.begin(); iter != cont.end(); ++iter) {
    if(*iter == elemToCount)
        ++counter;
    }
    return counter;
}

// map iterator
// The iterator of a map<string, int> points to a std::pair<string, int>.

// ---------------------------------------------------
// pair
std::pair<string, int> p;
p.first = "Phone number";
p.second = 6504550404;

// Quicker ways to make a pair:
std::pair<string, int> p{"Phone number", 6507232300};
std::make_pair("Phone number", 6507232300);
// make_pair automatically deduces the type! This is a great place to use auto!
auto time = std::make_pair(1, 45);

int main() {
    auto [min, max] = my_minmax(3, 6);
    cout << min << endl; // 3
    cout << max << endl; // 6
}
pair<int, int> my_minmax(int a, int b) {
    if (a < b) return {a, b};
    else return {b, a};
}


map<int, int> m;
map<int, int>::iterator i = m.begin();
map<int, int>::iterator end = m.end();
while(i != end) {
    cout << (*i).first << (*i).second << endl;
    ++i;
}

// set iterator
std::set<int>::iterator iter = mySet.begin();
int val = *iter;
iter++; // ++iter;
if (iter == mySet.end()) return;

// multimaps
// Doesn’t have [] operator! 
std::multimap<int, int> myMMap;
myMMap.insert(make_pair(3, 3));
myMMap.insert({3, 12}); // shorter syntax
cout << myMMap.count(3) << endl; // prints 2

// iterator uses
// sorting
std::sort(vec.begin(), vec.end());

const int elementToFind = 5;
vector<int>::iterator it = std::find(vec.begin(), vec.end(), elementToFind);
// find vs. count
// myMap.count(key) == 0;
// Does it work???
std::find(myMap.begin(), myMap.end(), key);
if (find(myMap.begin(), myMap.end(), key) == myMap.end())
    cout << “Not Found”;

set<int>::iterator iter = mySet.lower_bound(7);
set<int>::iterator end = mySet.lower_bound(26);
while (iter != end) {
    cout << *i << endl;
    ++i;
}

// range based for loop
map<string, int> myMap;
for(auto thing : myMap) {
    doSomething(thing.first, thing.second);
}
// < == >
map<string, int> myMap;
for(auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
    auto thing = *iter;
    doSomething(thing.first, thing.second);
}


// Struct
// Declaring the struct definition
struct Object {
    type var1;
    type var2;
}
// Initializing a struct object using uniform initialization
struct Object objName{value1, value2};
// “struct” keyword is optional in C++
// Operating on the struct object - in this case, assigning a
value
objName.var1 = newvalue1;

struct SimpleGraph { 
    vector<Node> nodes; 
    vector<Edge> edges; 
}
struct Node {
    double x;
    double y;
}
struct SimpleGraph graph{};
// How would you add a Node to the graph?
graph.nodes.push_back( {someXValue, someYValue} ); // can use initializer list
// automatically creates Node object + adds to vector


// -----------------------------------------
// Iterator Types

// There are 5 different types of iterators!
// 1. Input
// 2. Output
// 3. Forward
// 4. Bidirectional
// 5. Random access

// 1. For sequential, single-pass input:
// Read only i.e. can only be dereferenced on right side of expression.
vector<int> v = ...
vector<int>::iterator itr = v.begin();
int val = *itr;
// use cases:
// - find or count
// template<class InputIt, class T>
// InputIt find(InputIt first, InputIt last, const T& value);
// - input streams


// 2. For sequential, single-pass output:
// Write only i.e. can only be dereferenced on left side of expression.
vector<int> v = ...
vector<int>::iterator itr = v.begin();
*itr = 12;
// use cases:
// - copy: 
// template<class InputIt, class OutputIt>
// OutputIt copy(InputIt first, InputIt last, OutputIt d_first);
// - output stream


// 3. Forward Iterators
// Combines input and output iterators, + can make multiple passes.
// Can read from and write to (if not const iterator).
vector<int> v = ...
vector<int>::iterator itr = v.begin();
int val = *itr;
*itr = 12;
// use cases:
// - replace:
// template<class ForwardIt, class T>
// void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value);
// - forward_list (sequence containers, think of as singly-linked list)


// 4. Bidirectional Iterators
// Same as forward iterators, + can go backwards with the decrement operator (--).
vector<int> v = ...
vector<int>::iterator itr = v.begin();
++itr;
int val = *itr;
--itr;
int val2 = *itr;
// use cases:
// - reverse
template<class BidirIt>
void reverse(BidirIt first, BidirIt last);
// - std::map, std::set
// - std::list (sequence container, think of as doubly-linked list)


// 5. Random Access Iterators
// Same as bidirectional iterators, + can be incremented or decremented by arbitrary amounts using + and -.
vector<int> v = ...
vector<int>::iterator itr = v.begin();
int val = *itr;
itr = itr + 3;
int val2 = *itr;
// use cases:
// - std::vector, std::deque, std::string
// - Pointers


// erase in STL containers

// compare with vector, deque and list for different iterator types
vector<int> v{3, 1, 4, 1, 5, 2, 6};
auto iter = v.begin();
std::advance(iter, 4); // could also do iter += 4
v.erase(iter); // cannot erase by index


// -----------------------------------------
// templates
// The compiler literally replaces each template parameter with whatever you instantiate it with

template <typename T>
pair<T, T> my_minmax(T a, T b) {
    if (a < b) return {a, b};
    else return {b, a};
}

// Explicit Instantiation of Templates
my_minmax<string>(“Anna”, “Avery”);
// Compiler deduces; type deduction can’t read your mind
my_minmax(3, 4);
my_minmax(“Anna”, “Avery”); // Note: Compiler deduces T = char* (C-string) which causes comparing pointers, not what you want!

template <typename InputIt, typename DataType>
int countOccurences(InputIt begin, InputIt end, DataType val) {
    int count = 0;
    for (auto iter = begin; iter != end; ++iter) {
        if (*iter == val) ++count;
    }
    return count;
}

template <typename ForwardIt, typename T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value) {
     first = std::find(first, last, value);
     if (first != last)
          for(ForwardIt i = first; ++i != last; )
               if (!(*i == value))
      return first;
}

// c++20 concept lifting





// -----------------------------------------
// functors


// -----------------------------------------
// stl algorithms
const int kNumInts = 200;
std::vector<int> vec(kNumInts);
std::generate(vec.begin(), vec.end(), rand);
std::sort(vec.begin(), vec.end());
std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(count, "\n"));









