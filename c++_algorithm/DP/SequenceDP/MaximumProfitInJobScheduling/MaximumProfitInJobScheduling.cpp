// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// 1235. Maximum Profit in Job Scheduling

// 这道题是一道经典题了。涉及到了interval, sort, binary search and dp.
// interval需要考虑是按照起点还是终点排序。终点排序可以保证前面的区间都是完成的
// 然后按照当前区间的起点位置，寻找前面的终点位置来确定最优解。
// 这样的时间复杂度是O(nlogn)

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int,3>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        auto cmp = [](auto& l, auto& r) {
            if (l[1] == r[1]) {
                return l[0] < r[0];
            }
            return l[1] < r[1];
        };
        // sort by endTime
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int> ends;
        for (auto& x: jobs) {
            ends.push_back(x[1]);
        }

        int res = 0;
        // the optimized cost for the first n jobs
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i] = jobs[i][2];
                continue;
            }
            int start = jobs[i][0];
            auto it = upper_bound(ends.begin(), ends.end(), start);
            int idx = it - ends.begin() - 1;
            dp[i] = max(dp[i-1], (idx < 0 ? 0 : dp[idx]) + jobs[i][2]);
        }

        return dp[n-1];
    }
};