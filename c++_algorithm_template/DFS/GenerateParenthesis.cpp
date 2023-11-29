// https://leetcode.com/problems/generate-parentheses/

// Generate parenthesis

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string validParen = "";
        dfs(n, n, validParen);
        return res;
    }

    void dfs(int left, int right, string& validParen) {
        if (left == 0 && right == 0) {
            res.push_back(validParen);
            return;
        }
        if (left > 0) {
            validParen.push_back('(');
            dfs(left-1, right, validParen);
            validParen.pop_back();
        }
        if (right > left) {
            validParen.push_back(')');
            dfs(left, right-1, validParen);
            validParen.pop_back();
        }
    }
};
