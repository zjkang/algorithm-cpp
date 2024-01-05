// https://www.lintcode.com/problem/regular-expression-matching/description

// 10. Regular Expression Matching

// Implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).
// The function prototype should be:

// bool isMatch(string s, string p)

// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true


class Solution {
public:
    map<array<int,2>, bool> memo;
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }

    //source 从 i 开始的后缀能否匹配上 pattern 从 j 开始的后缀
    //能 return True
    bool helper(const string& s, int i, const string& p, int j) {
        if (memo.count({i,j})) return memo[{i,j}];
        if (s.size() == i) return is_empty(p.substr(j));
        if (j == p.size()) return false;
        bool matched = false;
        if (j + 1< p.size() && p[j+1] == '*') {
            matched = (is_match_char(s[i], p[j]) && helper(s,i+1,p,j)) ||
                helper(s,i,p,j+2);
        } else {
            matched = is_match_char(s[i],p[j]) && helper(s,i+1,p,j+1);
        }
        memo[{i,j}] = matched;
        return matched;
    }

    bool is_match_char(char s, char p) {
        return s == p || p == '.';
    }

    bool is_empty(const string& pattern) { // bind to rvalue
        if (pattern.size() % 2 == 1) return false;
        for (int i = 0; i < pattern.size() / 2 ; i++) {
            if (pattern[i*2+1] != '*')
                return false;
        }
        return true;
    }
};

