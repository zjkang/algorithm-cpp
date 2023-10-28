// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// 653. Two Sum IV - Input is a BST

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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> asc_stack;
        stack<TreeNode*> desc_stack;
        push_left(root, asc_stack);
        push_right(root, desc_stack);
        while (!asc_stack.empty()) {
            auto left = asc_stack.top();
            auto right = desc_stack.top();
            if (left == right) break;
            if (left->val + right->val == k) {
                return true;
            }
            if (left->val + right->val < k) {
                asc_stack.pop();
                push_left(left->right, asc_stack);
            } else {
                desc_stack.pop();
                push_right(right->left, desc_stack);
            }
        }
        return false;
    }

    void push_left(TreeNode* root, stack<TreeNode*>& asc_stack) {
        while (root) {
            asc_stack.push(root);
            root = root->left;
        }
    }

    void push_right(TreeNode* root, stack<TreeNode*>& desc_stack) {
        while (root) {
            desc_stack.push(root);
            root = root->right;
        }
    }
};