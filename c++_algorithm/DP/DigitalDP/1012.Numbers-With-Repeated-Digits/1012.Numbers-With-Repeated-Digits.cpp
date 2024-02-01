https://leetcode.com/problems/numbers-with-repeated-digits/
1012. Numbers With Repeated Digits

// 这道题和count special intergers基本上一模一样
// 这个dfs写法参考了群主的解法

class Solution {
    int ret = 0;
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int N = s.size();
        for (int i = 1; i <= N-1; i++) {
            ret += A(10, i) - A(9, i-1); // remove 0xx
        }

        vector<bool> visited(10, false);
        dfs(s, 0, visited);

        return n - ret;
    }

    void dfs(string& s, int idx, vector<bool>& visited) {
        int N = s.size();
        if (idx == N) {
            ret += 1;
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (i == 0 && idx == 0) continue;
            if (visited[i]) continue;
            if (i < s[idx]-'0') {
                ret += A(10-idx-1, N-idx-1); // use idx
            } else if (i == s[idx]-'0') {
                visited[i] = true;
                dfs(s, idx + 1, visited);
                visited[i] = false;
            } else {
                break;
            }
        }
    }

    int A(int m, int n) {
        int cur = 1;
        for (int i = 0; i < n; i++) {
            cur *= m-i;
        }
        return cur;
    }
};