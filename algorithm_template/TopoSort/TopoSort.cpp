// node indegree
// node neighbors out-pointed linked edge

// top排序有的时候和dfs的找环等价
// 这道题可以使用topo来写，另外一种方式是使用dfs找环
// 这道题的dfs找环的解法需要visited的tag有两个值
// visiting表示这个点已经访问，但是由这点扩展出来的connected component还没有全部完成
// visited表示这个点以及扩展出来的connected component已经全部完成


// topo template bfs

// Given an directed graph, a topological order of the graph nodes is defined as follow:
//   For each directed edge A -> B in graph, A must before B in the order list.
//   The first node in the order can be any node in the graph with no nodes direct to it.
//   Find any topological order for the given graph.
// You can assume that there is at least one topological order in the graph.

// Definition for a Directed graph node
struct DirectedGraphNode {
  int label;
  vector<int> neighbors;
  DirectedGraphNode(int x) : label(x) {}
};

vector<int> topSort(vector<DirectedGraphNode*>& graph) {
  vector<int> order;
  vector<DirectedGraphNode*> startNodes;
  auto nodeToIndegree = getIndegree(graph);
  for (auto node : graph) {
    if (nodetoIndegree[node] == 0) {
      startNodes.push_back(node);
    }
  }
  queue<DirectedGraphNode*> queue;
  for (auto node : startNodes) {
    queue.push(node);
  }
  while (!queue.empty()) {
    auto node = queue.front();
    queue.pop();
    order.push_back(node->label);
    for (auto neighbor : node->neighbors) {
      nodeToIndegree[neighbor]--;
      if (nodeToIndegree[neighbor] == 0) {
        queue.push(neighbor);
      }
    }
  }
  return order;
}

map<int, int> getIndegree(DirectedGraphNode& graph) {
  map<DirectedGraphNode*, int> nodeToIndegree;
  for (auto node : graph) {
    for (auto neighbor : node->neighbors) {
      nodeToIndegree[neighbor]++;
    }
  }
  return nodeToIndegree;
}


  
