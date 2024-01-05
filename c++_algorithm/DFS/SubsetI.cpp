// https://leetcode.com/problems/subsets/

// 78. Subsets

// Time complexity: O(2^n * n), leaf level: append result at terminating state O(n)
// Space complexity: dfs path (up <-> down) O(n); each level O(1) space
// select each element or no

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> oneset;
        dfs(nums, 0, oneset);
        return result;
    }

    void dfs(vector<int>& nums, int index, vector<int>& oneset) {
        if (index == nums.size()) {
            result.push_back(oneset);
            return;
        }
        // select nums[index]
        oneset.push_back(nums[index]);
        dfs(nums, index+1, oneset);
        oneset.pop_back();
        // not select nums[index]
        dfs(nums, index + 1, oneset);
    }
};


//  what to put for i-th element
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> oneset;
        dfs(nums, 0, oneset);
        return result;
    }

    void dfs(vector<int>& nums, int index, vector<int>& oneset) {
        result.push_back(oneset);
        for (int i = index; i < nums.size(); i++) {
            oneset.push_back(nums[i]);
            dfs(nums, i+1, oneset);
            oneset.pop_back();
        }
    }
};
