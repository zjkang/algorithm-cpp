// https://app.laicode.io/app/problem/456

// Minimum Number Of Coin Changes

// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)
// Example 2:
// coins = [2], amount = 3
// return -1.

// dp (52ms)
class Solution {
public:
  int coinChange(vector<int> coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i-c] + 1);
                }
            }
        }
        return dp[amount] != amount+1 ? dp[amount] : -1;
    }
};


// TLE
// class Solution {
//     map<array<int,2>, int> dp;
//     int coinChange(vector<int> coins, int amount) {
//         sort(coins.rbegin(), coins.rend()); // descreasing order
//         dfs(coins, 0, amount);
//     }

//     int dfs(vector<int>& coins, int start, int amount) {
//         if (start == coins.size()-1) {
//             return amount % coins.back() == 0 ? amount / coins.back() : -1;
//         }
//         if (dp.count({start, amount})) {
//             return dp[{start, amount}];
//         }
//         int num = 0;
//         int res = -1;
//         while (coins[start] * num <= amount) {
//             int restNum = dfs(coins, start+1, amount - coins[start]*num);
//             if (restNum != -1) {
//                 res == -1 ? num+restNum : min(res, num+restNum);
//             }
//             num++;
//         }
//         dp[{start, amount}] = res;
//         return res;
//     }
// }

// memorization (666ms)
class Solution {
public:
    int dp[12][10000+5];
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend()); // descreasing order
        return dfs(coins, 0, amount);
    }

    int dfs(vector<int>& coins, int start, int amount) {
        // cout << start << "," << coins[start] << "," << amount << endl;
        if (start == coins.size()-1) {
            return amount % coins.back() == 0 ? amount / coins.back() : -1;
        }
        if (dp[start][amount]) {
            return dp[start][amount];
        }
        int num = 0;
        int res = -1;
        while (coins[start] * num <= amount) {
            int restNum = dfs(coins, start+1, amount - coins[start]*num);
            if (restNum != -1) {
                res = res == -1 ? num+restNum : min(res, num+restNum);
            }
            num++;
        }
        dp[start][amount] = res;
        return res;
    }
};

