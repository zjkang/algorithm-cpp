// https://app.laicode.io/app/problem/73

// Combinations Of Coins

// Given a number of different denominations of coins (e.g., 1 cent, 5 cents, 10 cents, 25 cents),
// get all the possible ways to pay a target number of cents.
// Examples
// coins = {2, 1}, target = 4, the return should be
// [
//   [0, 4],   (4 cents can be conducted by 0 * 2 cents + 4 * 1 cents)
//   [1, 2],   (4 cents can be conducted by 1 * 2 cents + 2 * 1 cents)
//   [2, 0]    (4 cents can be conducted by 2 * 2 cents + 0 * 1 cents)
// ]


// Print all possible combinations (recursion or memoization)

class Solution {
    vector<vector<int>> result;
    vector<vector<int>> combinations(int target, vector<int>& coins) {
        vector<int> oneres;
        dfs(target, coins, 0, oneres);
        return result;
    }

    void dfs(int target, vector<int>& coins, int start, vector<int>& oneres) {
        if (start == coins.size()-1) {
            if (target % coins[start] == 0) {
                oneres.push_back(target / coins[start]);
                result.push_back(oneres);
                oneres.pop_back();
            return;
            }
        }
        int num = 0;
        while (num * coins[start] <= target) {
            oneres.push_back(target / coins[start]);
            dfs(target - num * coins[start], start+1, oneres);
            oneres.pop_back();
            num++;
        }
    }
}
