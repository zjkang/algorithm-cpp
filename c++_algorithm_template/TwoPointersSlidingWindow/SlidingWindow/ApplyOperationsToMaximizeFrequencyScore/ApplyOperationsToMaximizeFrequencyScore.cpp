// https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/
// 2968. Apply Operations to Maximize Frequency Score

// sliding window + median window + prefix sum

class Solution {
public:
    using LL = long long;
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<LL> pre_sum(n, 0);
        LL cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            pre_sum[i] = cur;
        }
        // sliding window
        int slow = 0, fast = 0;
        int ans = 0;
        while (fast < n) {
            while (calc(nums, pre_sum, slow, fast) > k) { 
                slow++;
            }
            ans = max(ans, fast-slow+1);
            fast++;
        }
        return ans;
    }

    // slow 1,  ... , fast 5  5
    // slow 1, .... , fast 6. 6
    LL calc(vector<int>& nums, vector<LL>& pre_sum, int slow, int fast) {
        // median value
        int mid = (slow + fast)/2;
        int m_num = nums[mid]; // select median value
        LL p1 = (long long)m_num*(mid-slow+1) - (pre_sum[mid]-(slow-1 < 0 ? 0 : pre_sum[slow-1]));
        LL p2 = pre_sum[fast]-pre_sum[mid] - (long long)m_num*(fast-mid);
        return p1 + p2;
    }
};