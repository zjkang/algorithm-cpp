
// 单调栈的2种可能需要方式

// 1. 第一个更大的数，找到左侧或者右侧离它最近的一个比它大或者小的数字
// 2. 表达式求值


// 1063. Number of Valid Subarrays
// https://leetcode.com/problems/number-of-valid-subarrays/
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


// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 上升单调栈维持矩形的左右边界
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        stack<int> stack;
        int N = heights.size();
        int i = 0;
        while (i < N + 1) {
            int val = i == N ? -1 : heights[i];
            while (!stack.empty() && heights[stack.top()] > val) {
                int top = stack.top(); stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                ret = max(ret, width * heights[top]);
            }
            stack.push(i);
            i++;
        }
        return ret;
    }
};
