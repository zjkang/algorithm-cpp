// https://leetcode.com/problems/binary-search-tree-iterator/
// 173. Binary Search Tree Iterator


// stack 中保存一路走到当前节点的所有节点，stack.peek() 一直指向 iterator 指向的当前节点。
// 因此判断有没有下一个，只需要判断 stack 是否为空
// 获得下一个值，只需要返回 stack.peek() 的值，并将 stack 进行相应的变化，挪到下一个点。

// 挪到下一个点的算法如下：
// 如果当前点存在右子树，那么就是右子树中"一路向西"最左边的那个点
// 如果当前点不存在右子树，则是走到当前点的路径中，第一个左拐的点

// 访问所有节点用时O(n)，所以均摊下来访问每个节点的时间复杂度时O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Stack中iterator的一般写法
// nextElem 维护下一个元素
// stack 维护路径的状态
class BSTIterator {
public:
    TreeNode* nextElem = nullptr;
    stack<TreeNode*> stack;

    BSTIterator(TreeNode* root) {
        getNext(root);
    }

    int next() {
        int ret = nextElem->val;
        getNext(nextElem->right);
        return ret;
    }

    void getNext(TreeNode* root) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
        if (stack.empty()) nextElem = nullptr;
        else {
            auto s = stack.top(); stack.pop();
            nextElem = s;
        }
    }

    bool hasNext() {
        return nextElem != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */