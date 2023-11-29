// https://en.cppreference.com/w/cpp/container/list
template<
    class T,
    class Allocator = std::allocator<T>
> class list;

list<int> l;
l.push_back(1); l.push_front(1);
l.pop_back(); l.pop_front();
l.empty(); l.size();
l.front(); l.back();
l.insert();

#include <algorithm>
#include <iostream>
#include <list>
 
int main()
{
    // Create a list containing integers
    std::list<int> l = {7, 5, 16, 8};
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end())
        l.insert(it, 42);
 
    // Print out the list
    std::cout << "l = { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";
}
