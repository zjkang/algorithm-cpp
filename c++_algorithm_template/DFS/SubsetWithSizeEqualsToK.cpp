// https://app.laicode.io/app/problem/640

// Subset with size == k

class Solution {
    vector<vector<int>> result;
    vector<vector<int>> subSetsOfSizeK(vector<int>& set, int k) {
        vector<int> oneset;
        dfs(set, 0, oneset, k);
        return result;
    }

    void dfs(vector<int>& set, int index, vector<int>& oneset, int k) {
        if (oneset.size() == k) {
            result.push_back(oneset);
            return;
        }
        if (index == set.size()) return;
        // select set[index]
        oneset.push_back(set[index]);
        dfs(set, index + 1, oneset, k);
        oneset.pop_back();
        // not select set[index]
        dfs(set, index + 1, oneset, k);
    }
}



