// https://app.laicode.io/app/problem/316

// Border View of Binary Tree

// Given a binary tree, return its border view. The border view is defined as follow: first get all the border nodes at left side(from root and always go to the left subtree unless the left subtree does not exist until reach a leaf node), then get all the leaf nodes(from left to right), at last get all the border nodes at right side(similar to left border but from bottom to top), the list of border view should not contain duplicate nodes. Note that for the given root, if it has no left sub-tree or right sub-tree, it is considered the left border/right border, but this rule applies to only the input tree not any sub-tree of it.
// Example 1:
//            1
//         /    \
//        2      3
//       / \    /  \
//      4   5   6  7
//       \          \
//        9           8
//           \
//             11
// the border view = [1, 2, 4, 9, 11, 5, 8, 7, 3]
// 1, 2, 4, 9, 11 are the left border, 11, 5, 8, 7 are the leaf nodes, 7, 3, 1 are the right border.
// Example 2:
//            1
//             \
//               3
//              /  \
//            4   5
//             \
//             6
// the border view = [1 6 5 3]
// In this case, the left border contains only one node [1], because the root doesn't have a left child.
// Example 3:
//                 /   \
//               2      3
//                \        \
//                 4       5
//                 /
//                6
// the border view = [1, 2, 4, 6, 5, 3]
// In this case, the left border contains [1, 2, 4, 6].

class Solution {
    vector<int> res;
    vector<int> borderView(TreeNode* root) {
        if (!root) return {};
        helper(root->left, true, false);
        helper(root->right, false, true);
        return res;
    }

    void helper(TreeNode* root, bool left_most, bool right_most) {
        if (!root) return;
        // pre-order for left bounary
        if (left_most || (!root->left && !root->right)) {
            res.push_back(root->val);
        }
        helper(root->left, left_most, root->right ? false : right_most);
        helper(root->right, root->left ? false : left_most, right_most);
        // post-order for right boundary
        if (right_most && !left_most && !(!root->left && !root->right)) {
            res.push_back(root->val);
        }
    }
};
