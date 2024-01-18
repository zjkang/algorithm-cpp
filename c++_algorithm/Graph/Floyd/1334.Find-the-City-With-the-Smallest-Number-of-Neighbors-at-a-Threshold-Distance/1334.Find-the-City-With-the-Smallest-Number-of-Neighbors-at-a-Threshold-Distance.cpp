// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Floyd算法的直接应用
// dp[i][j]: the shortest distance between node i and j


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX/2));
        for (auto& e : edges) {
            int c1 = e[0], c2 = e[1];
            int w = e[2];
            dp[c1][c2] = w;
            dp[c2][c1] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int min_count = INT_MAX;
        int city = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dp[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= min_count) {
                city = i;
                min_count = count;
            }
        }
        return city;
    }
};