// https://www.lintcode.com/problem/wildcard-matching/description

// Wildcard matching

// Implement wildcard pattern matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1
// Input:
// "aa"
// "a"
// Output: false

// Example 2
// Input:
// "aa"
// "aa"
// Output: true

// Example 3
// Input:
// "aaa"
// "aa"
// Output: false

// Example 4
// Input:
// "aa"
// "*"
// Output: true
// Explanation: '*' can replace any string

// Example 5
// Input:
// "aa"
// "a*"
// Output: true

// Example 6
// Input:
// "ab"
// "?*"

// Output: true
// Explanation: '?' -> 'a' '*' -> 'b'

// Example 7
// Input:
// "aab"
// "c*a*b"
// Output: false


class Solution {
public:
    bool isMatch(string s, string p) {
        s = "a" + s; p = "a" + p;
        int m = s.size(), n = p.size();
        // dp[i][j]: if there exists a match between s[i:] and p[j:]
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dfs(s, 0, p, 0, dp);
        return dp[0][0];
    }

    bool dfs(string& s, int i, string& p, int j, vector<vector<int>>& dp) {
        if (j == p.size()) return i == s.size();
        if (i == s.size()) {
            while (j < p.size()) {
                if (p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        bool matched = false;
        if (p[j] != '*') {
            if (s[i] == p[j] || p[j] == '?') {
                matched = dfs(s, i + 1, p, j + 1, dp);
            }
        } else {
            matched = dfs(s,i,p,j+1, dp) || dfs(s,i+1,p,j, dp);
        }

        dp[i][j] = matched ? 1 : 0;
        return matched;
    }
};