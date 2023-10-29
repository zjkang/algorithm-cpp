// https://app.laicode.io/app/problem/213

// Reconstruct Binary Tree w/ Preorder And Inorder
// 此类问题的要点就是把global的问题一分为二(recursively), 每半边返回一个subtree的root node.

// Given the preorder and inorder traversal sequence of a binary tree, reconstruct the original tree.
// Assumptions
// The given sequences are not null and they have the same length
// There are no duplicate keys in the binary tree
// Examples
// preorder traversal = {5, 3, 1, 4, 8, 11}
// inorder traversal = {1, 3, 4, 5, 8, 11}
// the corresponding binary tree is
//         5
//       /    \
//     3        8
//   /   \        \
// 1      4        11


class Solution {
    // preorder traversal = {5, 3, 1, 4, 8, 11}
    //  inorder traversal = {1, 3, 4, 5, 8, 11}
    TreeNode* reconstruct(vector<int>& inOrder, vector<int>& preOrder) {
        map<int,int> in_map;
        for (int i = 0; i < inOrder.size(); i++) {
            in_map[inOrder[i]] = i;
        }
        return dfs(preOrder, 0, preOrder.size()-1, 0, inOrder.size()-1, in_map);
    }

    TreeNode* dfs(vector<int>& pre_order, int pstart, int pend,
            int istart, int iend, map<int,int>& in_map) {
        if (pstart > pend) return nullptr;
        int val = pre_order[psstart];
        TreeNode* root = new TreeNode(val);
        int imid = in_map[val];

        root->left = dfs(pre_order, psstart + 1, psstart + imid - istart, istart, imid - 1, in_map);
        root->right = dfs(pre_order, psstart + imid - istart + 1, pend, imid + 1, iend, in_map);
        return root;
    }
}
