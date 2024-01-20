### BFS模板

BFS应该是最常见的算法题目了，数据结构就是queue。

如果以染‌色‌代‌表访问的每一个结点状‌态为例
白‌色‌-‌未‌进‌过‌queue‌ ‌
灰‌色‌-‌进‌过‌queue‌ ‌
黑‌色‌-‌出‌了‌queue

有的时候我们会压缩成enqueued or dequeued
enqueued角度:
白色 not enqueued,
灰色或者黑色 enqueued    -> BFS

dequeued角度:
白‌色灰‌色 not dequeued,
黑‌色 dequeued          -> priority queue


```cpp
// Q1.1 BFS Template w/o Level Traversal
// 无需分层遍历的宽度优先
queue<Node*> queue;
unordered_set<Node*> seen;
Node* start = new Node();
queue.push(start);
seen.insert(start);
while (!queue.empty()) {
    Node *head = queue.front(); queue.pop();
    for (auto neighbor : head->neighbors) {
        if (!seen.count(neighbor)) {
            seen.insert(neighbor);
            queue.push(neighbor);
        }
    }
}
```


```cpp
// Q1.2 BFS Template w/ Level Traversal
// 需要分层遍历的宽度
queue<int> queue;
unordered_set<int> seen;
Node* start = new Node();
queue.push(start);
seen.insert(start);
while (!queue.empty()) {
    int size = queue.size(); // retrieve size ahead
    for (int i = 0; i < size; ++i) {
        Node* head = queue.front(); queue.pop();
        for (auto neighbor : head->neighbors) {
            if (!seen.count(neighbor)) {
                seen.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}
```

```cpp
// Q1.3 BFS Template w/ Bi-Directional Traversal
// bi-directional bfs
void doubleBFS(Node* start, Node* end) {
    if (start == end)
        return 1;
    // 分别从起点和终点开始的两个BFS队列
    queue<Node*> startQueue, endQueue;
    startQueue.push(start);
    endQueue.push(end);

    int step = 0;
    // 从起点开始和从终点开始分别访问过的节点集合
    set<Node*> startVisited, endVisited;
    startVisited.insert(start);
    endVisited.insert(end);

    while (startQueue.size() && endQueue.size()) {
        int startSize = startQueue.size();
        int endSize = endQueue.size();
        // 按层遍历
        step++;
        for (int i = 0; i < startSize; i++) {
            auto cur = startQueue.top();
            startQueue.pop();
            for (auto neighbor : cur->neighbors) {
                if (startVisited.count(neighbor))
                    continue;
                else if (endVisited.count(neighbor))
                    return step;
                else {
                    startVisited.insert(neighbor);
                    startQueue.push(neighbor);
                }
            }
        }

        step++;
        for (int i = 0; i < endSize; i++) {
            auto cur = endQueue.top();
            endQueue.pop();
            for (auto neighbor : cur->neighbors){
                if (endVisited.count(neighbor))
                    continue;
                else if (startVisited.count(neighbor))
                    return step;
                else {
                    endVisited.insert(neighbor);
                    endQueue.push(neighbor);
                }
            }
        }
    }
    return -1;
}
```
