// https://leetcode.com/problems/remove-covered-intervals/
// 1288. Remove Covered Intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](auto& l, auto& r) {
            if (l[0] == r[0]) return r[1] < l[1];
            return l[0] < r[0];
        };
        // sort by pair first asc, second desc
        sort(intervals.begin(), intervals.end(), cmp);
        int removed = 0;
        int right_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= right_end) {
                removed++;
            } else {
                right_end = max(right_end, intervals[i][1]);
            }
        }
        return intervals.size() - removed;
    }
};