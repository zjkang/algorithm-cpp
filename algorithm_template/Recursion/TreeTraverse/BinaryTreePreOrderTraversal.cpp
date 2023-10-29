// preorder traversal

void preorder(TreeNode* root) {
    if (!root) return;
    visit(root); // visit the root
    preorder(root->left);
    preorder(root->right);
}

// iterative with stack
// 把root加进stack
// stack pop --> visit node
// node.right --> 把node.right加进stack
// node.left  -->  把node.left加进stack

void preorder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        auto cur = stack.top();
        stack.pop();
        visit(cur); // visit the root
        if (cur->right) {
            stack.push(cur->right);
        }
        if (cur->left) {
            stack.push(cur->left);
        }
    }
}


