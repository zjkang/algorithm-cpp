// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram

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