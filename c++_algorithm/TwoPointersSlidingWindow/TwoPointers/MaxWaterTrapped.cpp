// https://leetcode.com/problems/trapping-rain-water/
// Max Water Trapped

// Two pointers with maintaining max left and right value
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ret = 0;
        int leftMax = 0, rightMax = 0;
        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax > rightMax) {
                ret += rightMax - height[r];
                r--;
            } else {
                ret += leftMax - height[l];
                l++;
            }
        }
        return ret;
    }
};