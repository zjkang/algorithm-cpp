// https://leetcode.com/problems/sliding-window-maximum/
// Sliding Window Maximum
// Mono stack in desc


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deque; // desc stack
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