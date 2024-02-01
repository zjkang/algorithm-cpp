https://leetcode.com/problems/count-of-integers/



using LL = long long;
LL MOD = 1e9 + 7;
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        LL ret = 0;
        ret = ((countLessOrEqualThen(num2, max_sum) - countLessOrEqualThen(num2, min_sum-1) + MOD) % MOD) - (
                (countLessOrEqualThen(num1, max_sum) - countLessOrEqualThen(num1, min_sum-1) + MOD) % MOD);
        
        ret = (ret + MOD) % MOD;
        int cur = 0;
        for (char c: num1) {
            cur += c-'0';
        }
        if (cur >= min_sum && cur <= max_sum) ret = (ret + 1) % MOD;
        
        return ret;
    }
    
    LL countLessOrEqualThen(string& num, int max_sum) {
        // vector<vector<vector<int>>> memo(2, vector<vector<int>>(23, vector<int>(405, -1)));
        int memo[2][23][405];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 23; j++) {
                for (int k = 0; k < 405; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }
        return dfs(num, max_sum, 0, 0, true, memo);
    }
    
    LL dfs(string& num, int max_sum, int idx, int cur_sum, bool is_same, int memo[2][23][405]) {
        if (cur_sum > max_sum) return 0;
        if (idx == num.size()) return 1;
        if (memo[is_same][idx][cur_sum] != -1) return memo[is_same][idx][cur_sum];
        
        LL ret = 0;
        if (!is_same) {
            for (int d = 0; d <= 9; d++) {
                ret += dfs(num, max_sum, idx+1, cur_sum + d, false, memo);
                ret %= MOD;
            }
        } else {
            for (int d = 0; d < num[idx]-'0'; d++) {
                ret += dfs(num, max_sum, idx+1, cur_sum + d, false, memo);
                ret %= MOD;
            }
            ret += dfs(num, max_sum, idx+1, cur_sum + num[idx]-'0', true, memo);
            ret %= MOD;
        }

        ret %= MOD;
        memo[is_same][idx][cur_sum] = ret;
        return ret;
    }
};