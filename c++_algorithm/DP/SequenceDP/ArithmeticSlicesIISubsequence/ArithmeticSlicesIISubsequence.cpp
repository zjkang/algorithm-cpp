// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// 446. Arithmetic Slices II - Subsequence

// 这道题的难点在于构建dp的状态，因为是等差数列，所以可以想到diff是其中的一个状态
// 另外题目要求构建的序列的最小长度是3，这样要和前面连接成为最小长度为3的序列，要求满足
// 前面的序列长度最小为2.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i][diff]: ending with nums[i], number of equal differences >= 2
        vector<unordered_map<long, int>> dp(1000);
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                long diff = (long)nums[i] - (long)nums[j];
                if (dp[j].count(diff)) {
                    count += dp[j][diff];
                    dp[i][diff] += dp[j][diff]+1;
                } else {
                    dp[i][diff] += 1;
                }
            }
        }
        return count;
    }
};
