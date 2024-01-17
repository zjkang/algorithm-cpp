// https://leetcode.com/problems/max-consecutive-ones-iii/
// 1004. Max Consecutive Ones III

// 求最长的1s with at most k flips
// sliding window，动态伸长和收缩窗口的长度，同时flip操作
// 对于每一个终点，计算以它为终点的1s最长有多长with k flips

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] == 0) {
                k--;
            }
            while (slow <= fast && k < 0) {
                if (nums[slow] == 0) {
                    k++;
                }
                slow++;
            }
            ret = max(ret, fast - slow + 1);
            fast++;
        }
        return ret;
    }
};





