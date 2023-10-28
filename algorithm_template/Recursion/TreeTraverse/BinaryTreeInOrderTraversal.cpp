void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    visit(root); // visit the root
    inorder(root->right);
}

// iterative with stack
// 一路向左把点放进stack
// stack pop -->> visit node
// 访问右子树 (右子树一路向左放进stack)

void inorder(TreeNode* root) {
    stack<TreeNode*> stack;
    pushLeft(root, stack);
    while (!stack.empty()) {
        auto cur = stack.top();
        stack.pop();
        visit(cur->val);
        pushLeft(root->right, stack);
    }
}

void pushLeft(TreeNode* root, stack<TreeNode*>& stack) {
    while (root) {
        stack.push(root);
        root = root->left;
    }
}
