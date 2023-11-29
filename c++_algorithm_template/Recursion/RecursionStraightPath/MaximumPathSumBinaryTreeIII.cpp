// https://app.laicode.io/app/problem/140

// Q3 Maximum Path Sum Binary Tree III
// max subarray sum

// Given a binary tree in which each node contains an integer number. Find the maximum possible subpath sum(both the starting and ending node of the subpath should be on the same path from root to one of the leaf nodes, and the subpath is allowed to contain only one node).
// Assumptions
// The root of given binary tree is not null
// Examples
//    -5
//   /    \
// 2      11
//      /    \
//     6     14
//            /
//         -3
// The maximum path sum is 11 + 14 = 25


// M[i] = max subarray sum that ends at input[i]
// M[0] = input[0]
// M[i] = if M[i-1] < 0 then input[i], else M[i-1] + input[i]

// 直上直下keep track of current sum
int global_max = INT_MIN;
void helper(TreeNode* root, int sum) {
    if (!root) return;
    if (sum < 0) {
        sum = root->val;
    } else {
        sum += root->val;
    }
    global_max = max(global_max, sum);
    helper(root->left, sum);
    helper(root->right, sum);
}

// or 三部曲
int helper(TreeNode* root) {
    if (!root) return 0;
    int left = helper(root->left);
    int right = helper(root->right);
    int cur = max({left, right, 0}) + root->val;
    global_max = max(global_max, cur);
    return cur;
}
