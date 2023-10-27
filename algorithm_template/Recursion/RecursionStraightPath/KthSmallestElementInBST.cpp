// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Q2.1 Kth Smallest Element in BST
// high frequently search: build hash map <node, # of left nodes> when doing first search.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int globalRes = INT_MIN;
    int kth = 0;
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return globalRes;
    }

    void helper(TreeNode* root, int k) {
        if (!root) return;
        helper(root->left, k);
        if (kth == k) return;
        kth++;
        if (kth == k) {
            globalRes = root->val;
            return;
        }
        helper(root->right, k);
    }
};

// inorder iterative with stack
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return INT_MIN;
        stack<TreeNode*> stack;
        int cur_k = 0;
        pushLeftChild(root, stack);
        while (!stack.empty()) {
            auto cur = stack.top();
            stack.pop();
            cur_k++;
            if (cur_k == k) {
                return cur->val;
            }
            pushLeftChild(cur->right, stack);
        }
        return INT_MIN;
    }

    void pushLeftChild(TreeNode* root, stack<TreeNode*>& stack) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
    }
};
