// Recursion in 3 steps

// 1. What do you expect from your lchild / child? (usually it is the return type of the recursion function)
// 2. What do you want to do in the current layer?
// 3. What do you want to report to your parent (same as step 1)


// 人字形

// Q1 Binary Tree is Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// @return: return -1 or height of the tree


// Q2 Maximum Path Sum Binary Tree II
// https://app.laicode.io/app/problem/139
// 人字形 Get max sum of the path from any node to any node
// @return: the max sum starting from root node to node below
// @global max: update the result while traverse


// Q3 Lowest Common Ancestor (LCA)
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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