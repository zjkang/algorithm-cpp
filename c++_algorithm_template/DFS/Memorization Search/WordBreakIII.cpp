// https://www.lintcode.com/problem/word-break-iii/description

// Word Break III (结果数量)

// Example1
// Input:
// "CatMat"
// ["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
// Output: 3
// Explanation:
// we can form 3 sentences, as follows:
// "CatMat" = "Cat" + "Mat"
// "CatMat" = "Ca" + "tM" + "at"
// "CatMat" = "C" + "at" + "Mat"

// Example2
// Input:
// "a"
// []
// Output:
// 0


class Solution {
    unordered_map<int,int> memo;
    int wordBreak3(string s, vector<string> dict) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower)
        set<string> dictSet;
        int maxLength = 0;
        for (string& w : dict) {
            std::transform(w.begin(), w.end(), w.begin(), ::tolower);
            dictSet.insert(w);
            maxLength = max(maxLength, w.size());
        }
        return dfs(s, 0, maxLength, dictSet);
    }

    int dfs(string& s, int index, int maxLength, set<string>& dictSet) {
        if (index == s.size()) return 1;
        if (memo.count(index)) return memo[index];
        // # of work break starting from index to end of s
        memo[index] = 0;
        for (int i = index; i < s.size(); i++) {
            if (i-index+1 > maxLength) break;
            string word = s.substr(index, i-index+1);
            if (!dictSet.count(word)) continue;
            memo[index] += dfs(s, i+1, maxLength, dictSet);
        }
        return memo[index];
    }
}


// DP (划分dp的方法)
class Solution {
    int wordBreak3(string s, vector<string> dict) {
        if (s.size() == 0) return 0;
        int n = s.size();
        set<string> dictSet;
        for (string& w : dict) {
            std::transform(w.begin(), w.end(), w.begin(), ::tolower);
            dictSet.insert(w);
        }
        // dp[i][j] of word breaks for str between i and j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j-i+1);
                if (dictSet.count(sub)) {
                    dp[i][j] = 1;
                }
            }
        }
        // dp[0][i] = dp[0][k] * dp[k+1][i]  左大段 + 右大段
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < i; k++) {
                dp[0][i] += dp[0][k] * dp[k+1][i];
            }
        }
        return dp[0][n-1];
    }
}


// Linear Scan
class Solution {
    int wordBreak3(string s, vector<string> dict) {
        if (s.size() == 0) return 0;
        set<string> dictSet;
        for (string& w : dict) {
            std::transform(w.begin(), w.end(), w.begin(), ::tolower);
            dictSet.insert(w);
        }
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0;i < n; i++) {
            for (int j = i; j >= 0; j--) {
                // 左大段 + 右小段
                if (dictSet.count(s.substr(j, i-j+1))) {
                    dp[i] += (j == 0 ? 1 : dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
}
