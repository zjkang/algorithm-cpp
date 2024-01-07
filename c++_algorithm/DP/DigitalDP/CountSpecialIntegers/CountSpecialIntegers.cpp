// https://leetcode.com/problems/count-special-integers/
// 2376. Count Special Integers

// 参考模板;一位一位的放置数字，根据是否到达limit和是否前面都是0来确定可以放置的数字范围
// 通过mask来确定是否有重复的数字已经放置。

class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(1<<10, -1));

        function<int(int, int, bool, bool)> f = 
            [&](int i, int mask, bool isLimit, bool isNum) -> int {

            if (i == m) return isNum;
            if (!isLimit && isNum && dp[i][mask] >= 0) return dp[i][mask];
            int res = 0;
            if (!isNum) res = f(i + 1, mask, false, false); // 可以跳过当前数位
            int up = isLimit ? s[i] - '0' : 9;
            for (int d = (isNum ? 0 : 1); d <= up; ++d)
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), isLimit && d == up, true);
            if (!isLimit && isNum) dp[i][mask] = res;
            return res;
        };
        return f(0, 0, true, false);
    }
};
