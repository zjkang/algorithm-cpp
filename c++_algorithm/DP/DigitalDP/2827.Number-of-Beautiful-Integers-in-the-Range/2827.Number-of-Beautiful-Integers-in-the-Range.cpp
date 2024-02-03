// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/
// 2827. Number of Beautiful Integers in the Range

class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string low_str = to_string(low-1);
        string high_str = to_string(high);
        return countIntegers(high_str, k) - countIntegers(low_str, k);
    }

    int countIntegers(string& high, int k) {
        int memo[2][22][10][10];
        string s = "";
        int ret = 0;
        //考虑偶数长度
        for (int l = 2; l < high.size(); l+=2) {
            s += "99";
            memset(memo, -1, sizeof(memo));
            ret += dfs(s, 0, 0, 0, k, true, memo);
        }
        if (high.size() % 2 == 0) {
            memset(memo, -1, sizeof(memo));
            ret += dfs(high, 0, 0, 0, k, true, memo);
        }
        return ret;
    }

    // 考虑remain来确定是否可以被k整除
    int dfs(string& high, int idx, int num_of_even, int remain, int k, bool is_same, int memo[2][22][10][10]) {
        int N = high.size();
        if (num_of_even > N/2) return 0;
        if (idx == high.size()) {
            if (num_of_even == idx - num_of_even && (remain % k == 0)) {
                return 1;
            }
            return 0;
        }
        if (memo[is_same][remain][num_of_even][idx] != -1) {
            return memo[is_same][remain][num_of_even][idx];
        }
        int ret = 0;
        for (int d = 0; d <= 9; d++) {
            if (idx == 0 && d == 0) continue;
            if (is_same && d > high[idx]-'0') break;
            int next_remain = (remain * 10 + d) % k;
            if (d%2==0) {
                if (num_of_even+1 >N/2) continue;
                ret += dfs(high, idx+1, num_of_even+1, next_remain, k,  is_same && d == high[idx]-'0', memo);
            } else {
                if (idx+1-num_of_even > N/2) continue;
                ret += dfs(high, idx+1, num_of_even, next_remain, k, is_same && d == high[idx]-'0', memo);
            }
        }
        memo[is_same][remain][num_of_even][idx] = ret;
        return ret;
    }
};