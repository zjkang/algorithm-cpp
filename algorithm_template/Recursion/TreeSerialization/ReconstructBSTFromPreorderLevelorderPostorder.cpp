https://app.laicode.io/app/problem/210
https://app.laicode.io/app/problem/211
https://app.laicode.io/app/problem/212

// Preorder:
// M1: preorder + inorder (sort) ---> reconstruct time: O(nlogn) + O(n)
// M2: native 大问题到小问题 寻找分割点
// M3: min, max 区间法 一边遍历一边构造

class Solution {
    int idx = 0;
    TreeNode* reconstruct(vector<int>& pre) {
        return helper(pre, INT_MAX, INT_MIN);
    }

    TreeNode* helper(vector<int>& pre, int intMax, int intMin) {
        if (idx == pre.size() || pre[idx] >= intMax || pre[idx] <= intMin) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[idx]);
        idx++;
        root->left = helper(pre, root->val, intMin);
        root->right = helper(pre, intMax, root->val);
        return root;
    }
}
