// https://leetcode.com/problems/count-stepping-numbers-in-range/
// 2801. Count Stepping Numbers in Range

// 这道题写了差不多快40分钟，考虑是否有leading zero和是否一直存在和比较数字同样的数字(数字的boundary)


using LL = long long;
int MOD = 1e9 + 7;
class Solution {
public:
    int memo[2][2][10][105];
    int countSteppingNumbers(string low, string high) {
        LL ret = countNumber(high)-countNumber(low);
        ret = (ret + MOD) % MOD;

        bool is_valid = true;
        for (int i = 1; i < low.size(); i++) {
            if (abs(low[i]-low[i-1]) != 1) {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
            ret = (ret + 1) % MOD;
        return ret;
    }

    LL countNumber(string& high) {
        memset(memo,-1,sizeof(memo));
        // vector memo(2, vector<vector<vector<int>>>(2, vector<vector<int>>(10, vector<int>(105, -1))));
        return dfs(high, 0, 0, true, true, memo);
    }

    //is_same:表示是否前面所有的数字都和idx前面的相同
    //is_zero:表示现在是否都存在leading zeros
    LL dfs(string& high, int idx, int pre_digit, bool is_same, bool is_zero, int memo[2][2][10][105]) {
        if (idx == high.size()) return 1;
        if (memo[is_same][is_zero][pre_digit][idx] != -1)
            return memo[is_same][is_zero][pre_digit][idx];

        LL ret = 0;
        //先考虑是否存在leading zero
        //然后考虑可以取到的最大边界
        if (is_zero) {
            int upper = is_same ? high[idx]-'0' : 9;
            for (int d = 0; d <= upper; d++) {
                ret += dfs(high, idx+1, d, is_same && d == upper, is_zero && d == 0, memo);
                ret = ret % MOD;
            }
        } else {
            int upper = is_same ? high[idx] - '0' : 9;
            if (pre_digit+1 <= 9 && pre_digit+1 <= upper) {
                ret += dfs(high, idx+1, pre_digit+1, is_same && pre_digit+1 == upper, false, memo);
                ret = ret % MOD;
            }
            if (pre_digit-1 >= 0 && pre_digit-1 <= upper) {
                ret += dfs(high, idx+1, pre_digit-1, is_same && pre_digit-1 == upper, false, memo);
                ret = ret % MOD;
            }
        }

        memo[is_same][is_zero][pre_digit][idx] = ret;
        return ret;
    }
};




