https://leetcode.com/problems/non-overlapping-intervals/


// min removal to make non-overlaping intervals
https://leetcode.com/problems/non-overlapping-intervals/
// 435. Non-overlapping Intervals

// sort by ending time & greedy
// 按照结束时间处理non-overlapping interval

// min removal to make non-overlaping intervals
// max non-overlapping intervals size

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto& b) { return a[1] < b[1];});

        int ret = 0;
        int cur = intervals[0][1]; // 保留的non-overlapping interval
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= cur) {
                cur = intervals[i][1];
            } else {
                ret++;
            }
        }
        return ret;
    }
};