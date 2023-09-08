// https://en.cppreference.com/w/cpp/container/stack
template<
    class T,
    class Container = std::deque<T>
> class stack;

stack<int> s;
s.top();
s.push(1); s.pop();
s.empty(); s.size();
