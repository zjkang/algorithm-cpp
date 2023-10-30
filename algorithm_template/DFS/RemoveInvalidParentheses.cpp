// https://www.lintcode.com/problem/remove-invalid-parentheses/description

// Remove Invalid Parentheses

// Remove the minimum number of invalid parentheses in order to make the input string valid. 
// Return all possible results.
// Example 1:
// Input:
// "()())()"
// Ouput:
// ["(())()","()()()"]

class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        auto [left, right] = _LeftRightCount(s);
        _dfs(s, left, right, 0);
        return res;
    }

    void _dfs(string s, int left, int right, int start) {
        if (left == 0 && right == 0) {
            if (_isvalid(s)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i-1]) continue;
            if (s[i] == '(' && left >= 1) {
                _dfs(s.substr(0, i) + s.substr(i+1), left-1, right, i);
            }
            if (s[i] == ')' && right >=1) {
                _dfs(s.substr(0,i) + s.substr(i+1), left, right-1, i);
            }
        }
    }

    bool _isvalid(string& s) {
        auto [left, right] = _LeftRightCount(s);
        return left==0 && right==0;
    }

    // minimum # of left/right breaking balanced parenthesis to confirm valid result
    // left=right=1
    pair<int,int> _LeftRightCount(string& s) {
        int left = 0, right = 0;
        for (auto c : s) {
            if (c == '(') left++;
            if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        return {left, right};
    }
};






