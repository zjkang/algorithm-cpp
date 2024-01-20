// https://leetcode.com/problems/number-of-valid-subarrays/
// 1063. Number of Valid Subarrays

// leftmost element of the subarray not larger than other elements in the subarray

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> stack;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[stack.top()] > nums[i]) {
                res += i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            res += nums.size() - stack.top();
            stack.pop();
        }
        return res;
    }
};