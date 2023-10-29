// postorder traversal
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    visit(root); // visit the root
}


// iterative with stack
// 一路向下,有node.left加node.left进stack，否则有node.right加node.right进stack
// stack pop --> visit node
// node和stack顶节点比较,如果是左节点,将stack顶节点的右孩子重复1

void postorder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stack;
    pushChildren(root, stack);
    while (!stack.empty()) {
        auto cur = stack.top();
        stack.pop();
        visit(cur);
        if (!stack.empty() && stack.top()->left == cur) {
            pushChildren(stack.top()->right, stack);
        }
    }

}

void pushChildren(TreeNode* root, stack<TreeNode*>& stack) {
    while (root) {
        stack.push(root);
        if (root->left) root = root->left;
        root = root->right;
    }
}
