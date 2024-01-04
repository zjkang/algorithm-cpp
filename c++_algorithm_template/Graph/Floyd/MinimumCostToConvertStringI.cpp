// https://leetcode.com/problems/minimum-cost-to-convert-string-i/
// 2976. Minimum Cost to Convert String I

// 这道题是熟悉floyd算法的好时机
// 参考了huifeng的视频 https://www.youtube.com/watch?v=I2-r1cHY-74&t=272s
// 和灵神的这篇文章 https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solutions/2525946/dai-ni-fa-ming-floyd-suan-fa-cong-ji-yi-m8s51/

class Solution {
public:
    using LL = long long;
    // Floyd: calculate all shortest path in graph
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        LL dp[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = LLONG_MAX/2;
                }
            }
        }

        for (int i = 0; i < cost.size(); i++) {
            dp[original[i]-'a'][changed[i]-'a'] = min(dp[original[i]-'a'][changed[i]-'a'], (LL)cost[i]);
        }

        // Floyd: shortest path between i and j
        for (int k = 0; k < 26; k++) { // 逐次增加节点
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    // dp[i][k] + dp[k][j]: i -> k -> j 这段路径的最小值
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        LL res = 0;
        for (int i = 0; i < source.size(); i++) {
            int a = source[i]-'a';
            int b = target[i]-'a';
            if (dp[a][b] == LLONG_MAX/2) {
                return -1;
            }
            res += dp[a][b];
        }
        return res;
    }
};
