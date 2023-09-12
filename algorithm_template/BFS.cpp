// 染‌色‌代‌表访问的每一个结点状‌态‌ ‌
// 白‌色‌-‌未‌进‌过‌queue‌ ‌
// 灰‌色‌-‌进‌过‌queue‌ ‌
// 黑‌色‌-‌出‌了‌queue

// 有的时候我们会压缩成enqueued, or dequeued
// enqueued角度: 白色 not enqueued, 灰色或者黑色 enqueued    -> BFS
// dequeued角度: 白‌色灰‌色 not dequeued, 黑‌色 dequeued        -> priority queue/heap

// Q1.1 BFS Template w/o Level Traversal
// 无需分层遍历的宽度优先
queue<int> queue;
unordered_set<int> seen;
queue.push(start);
seen.insert(start);
while (!queue.empty()) {
  Node* head = queue.front(); 
  queue.pop();
  for (auto neighbor : head->neighbors) {
    if (!seen.count(neighbor)) {
      seen.insert(neighbor);
      queue.push(neighbor);
    }
  }
}


// Q1.2 BFS Template w/ Level Traversal
# 需要分层遍历的宽度
from collections import deque

queue = deque()
seen = set()

seen.add(start)
queue.append(start)
while len(queue):
    size = len(queue)
    for _ in range(size):
        head = queue.popleft()
        for neighbor in head.neighbors:
            if neighbor not in seen:
                seen.add(neighbor)
                queue.append(neighbor)

