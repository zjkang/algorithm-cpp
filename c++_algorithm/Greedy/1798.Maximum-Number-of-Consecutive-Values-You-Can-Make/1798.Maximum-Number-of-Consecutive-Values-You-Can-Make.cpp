https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
1798. Maximum Number of Consecutive Values You Can Make

// 这道题和330 patch array类似
// 本质是如果当前的cur(当前的和)可以cover coins[i],也就是可以进一步扩展cur为cur + coins[i]

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int cur = 0;
        for (size_t i = 0; i < coins.size(); i++) {
            if (cur + 1 >= coins[i]) {
                cur += coins[i];
            } else {
                break;
            }
        }
        return cur+1;
    }
};