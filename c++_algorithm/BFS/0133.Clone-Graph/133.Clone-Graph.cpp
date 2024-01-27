// https://leetcode.com/problems/clone-graph/
// 133. Clone Graph

// 2次遍历(DFS/BFS)
// 遍历图保存新旧Node的mapping关系
// 遍历clone图的表示

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    set<Node*> visited;
    map<Node*, Node*> mapping;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        getNodes(node);
        visited.clear();
        cloneNode(node);
        return mapping[node];
    }

    void cloneNode(Node* node) {
        if (visited.count(node)) return;
        Node* copyNode = mapping[node];
        visited.insert(node);
        for (auto nei : node->neighbors) {
            copyNode->neighbors.push_back(mapping[nei]);
            cloneNode(nei);
        }
    }

    void getNodes(Node* node) {
        if (visited.count(node)) {
            return;
        }
        mapping[node] = new Node(node->val);
        visited.insert(node);
        for (auto nei : node->neighbors) {
            getNodes(nei);
        }
    }
};