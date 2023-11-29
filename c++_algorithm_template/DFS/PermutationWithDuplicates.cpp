// https://www.lintcode.com/problem/permutations

// Permutation with Duplicates

// Method 1: Use visited tags
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited = vector<bool>(nums.size(), false);
        vector<int> perm;
        dfs(nums, 0, perm);
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& perm) {
        if (start == nums.size()) {
            res.push_back(perm);
            return;
        }
        int pre = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i] && (pre == -1 || pre != nums[i])) {
                perm.push_back(nums[i]);
                visited[i] = true;
                pre = nums[i];
                dfs(nums, start+1, perm);
                visited[i] = false;
                perm.pop_back();
            }
        }
    }
};


// Method 2: Use swap to avoid visited array
// handle duplicate permutation with visited
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> visited; // record duplicated visits
        for (int i = index; i < nums.size(); i++) {
            if (!visited.count(nums[i])) {
                visited.insert(nums[i]);
                swap(nums[i], nums[index]);
                dfs(nums, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
};

