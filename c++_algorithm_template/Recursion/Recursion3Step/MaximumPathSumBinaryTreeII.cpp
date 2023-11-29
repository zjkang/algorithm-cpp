// https://app.laicode.io/app/problem/139

// Maximum Path Sum Binary Tree II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_val = INT_MIN;
    TreeNode* maxPathSum(TreeNode* root) {
        helper(root);
        return max_val;
    }

    int helper(TreeNode* root) {
        if (!root) return 0;
        auto left = helper(root->left);
        auto right = helper(root->right);
        left = max(0, left);
        right = max(0, right);
        max_val = max(root->val + left + right, max_val);
        return root->val + max(left, right);
    }
};