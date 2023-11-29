// https://app.laicode.io/app/problem/215

// Reconstruct Binary Tree w/ Levelorder And Inorder

// Given the levelorder and inorder traversal sequence of a binary tree, reconstruct the original tree.
// Assumptions
// The given sequences are not null and they have the same length
// There are no duplicate keys in the binary tree
// Examples
// levelorder traversal = {5, 3, 8, 1, 4, 11}
// inorder traversal = {1, 3, 4, 5, 8, 11}
// the corresponding binary tree is
//         5
//       /    \
//     3        8
//   /   \        \
// 1      4        11


class Solution {
    TreeNode* reconstruct(vector<int>& inOrder, vector<int>& levelOrder) {
        map<int,int> inMap;
        for (int i = 0; i < levelOrder.size(); i++) {
            inMap[levelOrder[i]] = i;
        }
        deque<int> deque(levelOrder.begin(), levelOrder.end());
        return helper(deque, inMap);
    }

    TreeNode* helper(deque<int>& levelOrder, map<int,int>& inMap) {
        if (levelOrder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(levelOrder[0]);
        levelOrder.pop_front();
        deque<int> left;
        deque<int> right;
        for (auto v : levelOrder) {
            if (inMap[v] < inMap[root->val]) {
                left.push_back(v);
            } else {
                right.push_back(v);
            }
        }
        root->left = helper(left, inMap);
        root->right = helper(right, inMap);
        return root;
    }
}

