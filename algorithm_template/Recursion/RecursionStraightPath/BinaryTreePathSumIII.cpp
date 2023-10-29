// https://www.lintcode.com/problem/binary-tree-path-sum-iii/

// Binary Tree Path Sum III

// Description
// Give a binary tree, and a target number, find all path that the sum of nodes equal to target,
// the path could be start and end at any node in the tree.

// Example
// Given binary tree:

//     1
//    / \
//   2   3
//  /
// 4
// and target = 6. Return :

// [
//   [2, 4],
//   [2, 1, 3],
//   [3, 1, 2],
//   [4, 2]
// ]

// 思路
// 现在的题意是可以从任何一点出发，而且有parent节点。
// 那么我们其实是traverse一遍这棵树，在每一点，我们出发找有没有符合条件的路径。
// 在每一点我们可以有三个方向：左边，右边，和上面。但是我们需要避免回头，所以需要一个from节点的参数。

// struct ParentTreeNode {
//     int val;
//     ParentTreeNode* parent;
//     ParentTreeNode* left;
//     ParentTreeNode* right;
//     ParentTreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };
vector<vector<int>> results;
vector<vector<int>> binaryTreePathSum3(ParentTreeNode* root, int target) {
    dfs(root, target);
    return results;
}

void dfs(ParentTreeNode* root, int target) {
    if (!root) return;
    vector<int> path;
    // find result passing root node
    findSum(root, nullptr, target, path);
    dfs(root->left, target);
    dfs(root->right, target);
}

void findSum(ParentTreeNode* root, ParentTreeNode* source, vector<int>& path) {
    path.push_back(root->val);
    target -= root->val;
    if (target == 0) {
        results.push_back(path);
    }
    if (root->parent && root->parent != source) {
        findSum(root->parent, root, target, path);
    }
    if (root->left && root->left != source) {
        findSum(root->left, root, target, path);
    }
    if (root->right && root->right != source) {
        findSum(root->right, root, target, path);
    }
    path.pop_back();
}
