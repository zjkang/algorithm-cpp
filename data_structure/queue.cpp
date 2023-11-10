// https://en.cppreference.com/w/cpp/container/queue
template<
    class T,
    class Container = std::deque<T>
> class queue;

queue<int> q;
q.front(); // there is no q.top(); 
q.back();
q.empty(); 
q.size();
q.push(u); // push to the end of the queue
void q.pop(); // remove the first element
