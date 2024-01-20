// https://leetcode.com/problems/sliding-window-maximum/
// 239. Sliding Window Maximum
// Mono deque in desc order

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deque;
        for (size_t i = 0; i < nums.size(); i++) {
            while (!deque.empty() && nums[deque.back()] <= nums[i]) {
                deque.pop_back();
            }
            deque.push_back(i);
            if (i < k - 1) continue;
            if (i - deque.front() + 1 > k) {
                deque.pop_front();
            }
            result.push_back(nums[deque.front()]);
        }
        return result;
    }
};