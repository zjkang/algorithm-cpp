// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Q3 Lowest Common Ancestor (LCA)

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left = helper(root->left, p, q);
        auto right = helper(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};