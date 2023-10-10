// Q2 Smallest k Elements in an Unsorted Array
// Find the kth smallest number in an unsorted integer array.

// Example
// Example 1:
// Input: [3, 4, 1, 2, 5], k = 3
// Output: 3

// Example 2:
// Input: [1, 1, 1], k = 2
// Output: 1

class Solution {
    int kthSmallest(int k, vector<int> nums) {
        priority_queue<int, vector<int>> pq;
        for (auto num : nums) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (num < pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
