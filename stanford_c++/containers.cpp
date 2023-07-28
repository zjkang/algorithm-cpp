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








// iterators

// functors


// -----------------------------------------
// stl algorithms
const int kNumInts = 200;
std::vector<int> vec(kNumInts);
std::generate(vec.begin(), vec.end(), rand);
std::sort(vec.begin(), vec.end());
std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(count, "\n"));









