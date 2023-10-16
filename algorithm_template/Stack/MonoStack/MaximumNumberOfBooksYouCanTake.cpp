https://leetcode.com/problems/maximum-number-of-books-you-can-take/
2355. Maximum Number of Books You Can Take

// refer to huifeng
// https://www.youtube.com/watch?v=iJsbDfza-qk
// dp + mono stack

using LL = long long;
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<LL> dp(n, 0); // dp[i]: the max books ending at position i
        stack<LL> stack;

        LL ret = 0;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && books[stack.top()] > books[i]-(i-stack.top())) { // expected # of books
                stack.pop();
            }

            if (!stack.empty()) {
                LL d = i - stack.top();
                dp[i] = dp[stack.top()] + (books[i] + books[i] - d + 1) * d /2;
            }
            else {
                LL d = min(i + 1, books[i]);
                dp[i] = (books[i] + books[i] - d + 1) * d /2;
            }
            stack.push(i);

            ret = max(ret, dp[i]);
        }

        return ret;
    }
};