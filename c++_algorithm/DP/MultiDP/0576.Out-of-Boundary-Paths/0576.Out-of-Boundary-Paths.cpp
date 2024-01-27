// https://leetcode.com/problems/out-of-boundary-paths/
// 576. Out of Boundary Paths

// dp[k][i][j]: the number of paths for k moves to position i,j

class Solution {
public:
    using LL = long long;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1e9 + 7;
        LL dp[maxMove+1][m+2][n+2];
        for (int k = 0; k <= maxMove; k++) {
            for (int i = 0; i <= m+1; i++) {
                for (int j = 0; j <= n+1; j++) {
                    dp[k][i][j] = 0;
                }
            }
        }
        dp[0][startRow+1][startColumn+1] = 1;

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        LL ret = 0;

        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i <= m+1; i++) {
                for (int j = 0; j <= n+1; j++) {
                    for (int d = 0; d < 4; d++) {
                        int cx = i + dx[d];
                        int cy = j + dy[d];
                        if (cx >= 1 && cx <= m && cy >= 1 && cy <= n) {
                            dp[k][i][j] += dp[k-1][cx][cy]; 
                            dp[k][i][j] %= MOD;
                        }
                    }
                    if (i == 0 || i == m+1 || 
                         j == 0 || j == n+1) {
                        ret += dp[k][i][j];
                        ret %= MOD;
                    }
                }
            }
        }
        return ret;
    }
};