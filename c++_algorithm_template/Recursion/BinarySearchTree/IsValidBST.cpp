https://leetcode.com/problems/validate-binary-search-tree/

// 98. Validate Binary Search Tree

// Inorder traversal: ascending order
// Search in BST ===> Binary Search O(height) (balanced: O(logn))
// 和binary search做类比

// 区间法
class Solution {
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }

    bool helper(TreeNode* root, int maxVal, int minVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return helper(root->left, root->val, minVal) &&
            helper(root->right, root->val, maxVal);
    }
}