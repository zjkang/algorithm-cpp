// https://www.lintcode.com/problem/word-break-ii/description

// Word Break II (详细结果)

// Input:"lintcode",["de","ding","co","code","lint"]
// Output:["lint code", "lint co de"]
// Explanation:
// insert a space is "lint code",insert two spaces is "lint co de".

// word dict: {word: word break solution list}


class Solution {
public:
    map<string,vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet);
    }

    vector<string> dfs(string& s, set<string>& wordSet) {
        if (s == "") {
            memo[s] = {""};
            return memo[s];
        }
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        vector<string> res;
        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            string remain = s.substr(i);
            if (wordSet.count(word)) {
                auto wordList = dfs(remain, wordSet);
                for (string& w : wordList) {
                    res.push_back(w == "" ? word : word + " " + w);
                }
            }
        }
        memo[s] = res;
        return res;
    }
};
