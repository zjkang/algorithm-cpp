// binary search + 中心开花
//     - sorted array -> Time: O(logn + k)
//     - bst -> Time: O(height + k)

// sorted array / bst
//     closest element
//     how to i++, j--

// Given a binary search tree, a target number and an integer k, return k closest elements to the target. 
// 1 <= K <= number of nodes in the tree.
// Note:
// In case of same distance, smaller number is considered closer.

// struct TreeNode {
//     int val = 0;
//     TreeNode* left = nullptr;
//     TreeNode* right = nullptr;
//     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };

class Solution {
    vector<int> kClosestBST(TreeNode* root, int target, int k) {
        // find closest node in bst
        auto node = find_closest_node(root, target);
        if (k == 1) {
            return {node->val};
        }
        stack<TreeNode*> asc_stack;
        stack<TreeNode*> desc_stack;
        init_asc_stack(root, node, asc_stack);
        init_desc_stack(root, node, desc_stack);

        vector<int> res = {node->val};
        int num = 1;
        while (!asc_stack.empty() && !desc_stack.empty() && num < k) {
            auto asc_node = asc_stack.top();
            auto desc_node = desc_stack.top();
            if (abs(desc_node->val - target) <= abs(asc_node->val - target)) {
                res.push_back(desc_node->val);
                desc_stack.pop();
                push_right(desc_node->left, desc_stack);
            } else {
                res.push_back(asc_node->val);
                asc_stack.pop();
                push_left(asc_node->right, asc_stack);
            }
            num++;
        }

        while (!asc_stack.empty() && num < k) {
            auto asc_node = asc_stack.top();
            res.push_back(asc_node->val);
            sc_stack.pop();
            push_left(asc_node->right, asc_stack);
            num++;
        }

        while (!desc_stack.empty() && num < k) {
            auto desc_node = desc_stack.top();
            res.push_back(asc_node->val);
            asc_stack.pop();
            push_left(asc_node->right, asc_stack);
            num++;
        }

        retrun res;

    }

    TreeNode* find_closest_node(TreeNode* root, int target) {
        while (root) {
            if (root->val == target) {
                return root;
            }
            if (root->val > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }

    void init_asc_stack(TreeNode* root, TreeNode* node, stack<TreeNode*>& asc_stack) {
        TreeNode* cur = root;
        while (cur != node) {
            if (cur->val > node->val) {
                asc_stack.push(cur);
                cur = cur->left;
            } else {
                cut = cur->right;
            }
        }
        // add the next node to stack
        push_left(cur->right, asc_stack);
    }

    void init_desc_stack(TreeNode* root, TreeNode* node, stack<TreeNode*>& desc_stack) {
        TreeNode* cur = root;
        while (cur != node) {
            if (cur->val < node->val) {
                desc_stack.push(cur);
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        // add the previous node to stack
        push_right(cur->left, desc_stack);
    }

    void push_left(TreeNode* root, stack<TreeNode*>& asc_stack) {
        while (root) {
            asc_stack.push(root);
            root = root->left;
        }
    }

    void push_right(TreeNode* root, stack<TreeNode*>& desc_stack) {
        while (root) {
            desc_stack.push(root);
            root = root->right;
        }
    }
};







