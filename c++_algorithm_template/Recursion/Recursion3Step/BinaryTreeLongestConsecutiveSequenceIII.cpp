// https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-iii/

// Q3 Binary Tree Longest Consecutive Sequence III

/**
 * Definition for a binary tree node.
 * struct MultiTreeNode {
 *     int val;
 *     vector<MultiTreeNode*> children;
 *     TreeNode(int x) : val(x) {}
 * };
 */
class Solution {
public:
    int max_val = INT_MIN;
    int longestConsecutive3(MultiTreeNode* root) {
        return dfs(root);
    }

    // pair for {'increase': 0, 'decrease': 0}
    pair<int,int> dfs(MultiTreeNode* root) {
        if (!root) return {0, 0};
        pair<int,int> cur = {1, 1};
        for (auto child : root->children) {
            auto childLen = dfs(child);
            if (root->val == child->val - 1) { // increase
                cur[0] = max(cur[0], childLen[0] + 1);
            }
            if (root->val == child->val + 1) { // decrease
                cur[1] = max(cur[1], childLen[1] + 1);
            }
        }
        max_val = max(max_val, cur[0] + cur[1] - 1);
        return cur;
    }
};
