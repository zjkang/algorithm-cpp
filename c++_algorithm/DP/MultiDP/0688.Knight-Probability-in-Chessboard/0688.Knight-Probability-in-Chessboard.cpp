// https://leetcode.com/problems/knight-probability-in-chessboard/
// 688. Knight Probability in Chessboard

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // vector dp(k + 1, vector(n, vector<double>(n, 0.0)));
        double dp[k+1][n][n];
        for (int ii = 0; ii < k+1; ii++) {
            for (int jj = 0; jj < n; jj++) {
                for (int kk = 0; kk < n; kk++) {
                    dp[ii][jj][kk] = 0.0;
                }
            }
        }
        
        dp[0][row][column] = 1.0;
        
        int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        
        for (int K = 1; K <= k; K++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 8; d++) {
                        int cx = i + dx[d];
                        int cy = j + dy[d];
                        if (cx >= 0 && cx < n && cy >= 0 && cy < n) {
                            dp[K][i][j] += 1.0/8.0 * dp[K-1][cx][cy];
                        }
                    }
                }
            }
        }        
        
        double res = 0.0;
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                res += dp[k][ii][jj];
            }
        }
        return res;
    }
};