// https://app.laicode.io/app/problem/663

// Number of Combination of Coin Changes


// dp[i]: the number of combinations for amount i
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = dp[i] + dp[i - coin];
            }
        }
        return dp[amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            dp[i][0] = i % coins[0] == 0 ? 1 : 0;
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j-1];
                if (i - coins[j] >= 0)  {
                    dp[i][j] += dp[i-coins[j]][j];
                }
            }
        }
        return dp[amount][n-1];
    }
};
