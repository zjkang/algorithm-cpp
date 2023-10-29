// https://app.laicode.io/app/problem/523
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Flatten Binary Tree to Linked List
// Memory storage (tree structure) into disk storage (hardware) with json, xml format.

// For example,
// Given
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6

// The flattened tree should look like:
//   1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// similar to post-order traversal (right -> left -> root)

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
    void flatten(TreeNode* root) {
        helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        if (!root) return nullptr;
        auto leftLast = helper(root->left);
        auto rightLast = helper(root->right);
        if (leftLast) {
            leftLast->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
        return rightLast ? rightLast : (leftLast ? leftLast : root);
    }
};