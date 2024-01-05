// https://app.laicode.io/app/problem/141

// Binary Tree Path Sum To Target III
// prefix sum + 2 sum

// Given a binary tree in which each node contains an integer number. Determine if there exists a
// path (the path can only be from one node to itself or to any of its descendants), the sum of the
// numbers on the path is the given target number.
// Examples
//     5
//   /    \
// 2      11
//      /    \
//     6     14
//   /
//  3
// If target = 17, There exists a path 11 + 6, the sum of the path is target.
// If target = 20, There exists a path 11 + 6 + 3, the sum of the path is target.
// If target = 10, There does not exist any paths sum of which is target.
// If target = 11, There exists a path only containing the node 11.

// class Solution {
//  public:
//   bool exist(TreeNode* root, int target) {
//     // write your solution here
//   }
// };

class Solution {
public:
    bool exist(TreeNode* root, int target) {
        set<int> prefixSums = {0};
        return helper(root, prefixSums, 0, target);
    }

    bool helper(TreeNode* root, set<int>& prefixSums, int prevSum, int target) {
        if (!root) return false;
        prevSum += root->value;
        if (prefixSums.count(prevSum - target)) {
            return true;
        }
        bool needUpdate = false;
        if (!prefixSums.count(prevSum)) {
            needUpdate = true;
            prefixSums.insert(prevSum);
        }
        if (helper(root->left, prefixSums, prevSum, target)) {
            return true;
        }
        if (helper(root->right, prefixSums, prevSum, target)) {
            return true;
        }
        if (needUpdate) {
            prefixSums.erase(prevSum);
        }
        return false;
    }
};


