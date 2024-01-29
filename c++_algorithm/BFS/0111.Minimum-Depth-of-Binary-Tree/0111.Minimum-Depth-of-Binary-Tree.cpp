// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// 111. Minimum Depth of Binary Tree

// BFS on binary tree

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (!node->left && !node->right) {
                    return depth + 1;
                }
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};