// 1063. Number of Valid Subarrays
// https://leetcode.com/problems/number-of-valid-subarrays/

// 单调栈的2种可能需要方式

// 1. 第一个更大的数，找到左侧或者右侧离它最近的一个比它大或者小的数字
// 2. 表达式求值

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> stack;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
        	// template
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