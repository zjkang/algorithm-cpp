// node indegree
// node neighbors out-pointed linked edge

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




  
