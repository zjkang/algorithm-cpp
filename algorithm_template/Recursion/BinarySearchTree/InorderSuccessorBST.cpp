// https://leetcode.com/problems/inorder-successor-in-bst/

// 285. Inorder Successor in BST

// smallest larger than
// largest smaller than
// similar problem: BST find closest node to the target

TreeNode inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* res = nullptr;
    while (root) {
        if (root->val > p->val) {
            res = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return res;
}
