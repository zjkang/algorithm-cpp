// https://app.laicode.io/app/problem/63

// Subset II

// deduplicate: determine to dedup at each position
// insert order (e.g. select first, then not select for all duplicate numbers)
// use hash to dedup

class Solution {
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> oneset;
        dfs(nums, 0, oneset);
        return result;
    }

    void dfs(vector<int>& nums, int index, vector<int>& cur) {
        if (index == nums.size()) {
            result.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        dfs(nums, index+1, cur);
        cur.pop_back();
        // not selected
        while (index+1 < nums.size() && nums[index] == nums[index+1]) {
            index++;
        }
        dfs(nums, index+1, cur);
    }
};