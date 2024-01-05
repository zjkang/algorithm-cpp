// https://cplusplus.com/reference/iterator/

// Input (Read)    <-- Forward   <-- Bidirectional  <-- Random Access

// Output (Write)

// begin, end, prev, next, back_inserter
int foo[] = {10,20,30,40,50};
std::vector<int> bar;
// iterate foo: inserting into bar
for (auto it = std::begin(foo); it!=std::end(foo); ++it) {
    bar.push_back(*it);
}
it = begin(bar);
it = end(bar);
it = prev(it);
it = next(it);

// back_inserter
// https://en.cppreference.com/w/cpp/iterator/back_inserter
template<class Container>
std::back_insert_iterator<Container> back_inserter(Container& c)
{
    return std::back_insert_iterator<Container>(c);
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::fill_n(std::back_inserter(v), 3, -1);
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}
// output: 1 2 3 4 5 6 7 8 9 10 -1 -1 -1


// distance
// https://en.cppreference.com/w/cpp/iterator/distance
#include <iostream>
#include <iterator>
#include <vector>
 
int main() 
{
    std::vector<int> v{3, 1, 4};
    std::cout << "distance(first, last) = "
              << std::distance(v.begin(), v.end()) << '\n'
              << "distance(last, first) = "
              << std::distance(v.end(), v.begin()) << '\n';
              // the behavior is undefined (until LWG940)
 
    static constexpr auto il = {3, 1, 4};
    // Since C++17 `distance` can be used in constexpr context.
    static_assert(std::distance(il.begin(), il.end()) == 3);
    static_assert(std::distance(il.end(), il.begin()) == -3);
}

// adv(iterator, step);

