// https://app.laicode.io/app/problem/233

// Queens

class Solution {
    vector<vector<int>> result;
    vector<vector<int>> nqueens(int n) {
        vector<int> oneRes;
        dfs(n, 0, oneRes);
        return result;
    }

    void dfs(int n, int row, vector<int>& oneRes) {
        if (n == row) {
            result.push_back(oneRes);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!has_conflict(row, i, oneRes)) {
                oneRes.push_back(i);
                dfs(n, row+1, oneRes);
                oneRes.pop_back();
            }
        }
    }

    bool has_conflict(int curR, int curC, vector<int>& oneRes) {
        for (int r = 0; r < oneRes.size(); r++) {
            int c = oneRes[r];
            if (c == curC || abs(curR-r) == abs(curC-c)) return true;
        }
        return false;
    }
}


