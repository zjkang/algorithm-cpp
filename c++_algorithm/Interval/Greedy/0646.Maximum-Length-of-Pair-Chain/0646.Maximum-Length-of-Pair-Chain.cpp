// https://leetcode.com/problems/maximum-length-of-pair-chain/
// 646. Maximum Length of Pair Chain

// 这道题和435一模一样


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int curr = INT_MIN, ret = 0;
        for (const auto& pair : pairs) {
            if (pair[0] > curr) {
                ret++;
                curr = pair[1];
            }
        }
        return ret;
    }
};