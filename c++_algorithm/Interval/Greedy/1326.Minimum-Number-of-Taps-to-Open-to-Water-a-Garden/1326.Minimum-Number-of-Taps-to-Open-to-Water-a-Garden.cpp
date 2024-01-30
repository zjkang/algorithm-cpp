// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// 1326. Minimum Number of Taps to Open to Water a Garden

// We need to cover the interval [0, n]. we can start with the first interval 
// and out of all intervals that intersect with it we choose the one that 
// covers the farthest point to the righ

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;
        for (int i = 0; i < ranges.size(); i++) {
            intervals.push_back({max(0,i-ranges[i]), i+ranges[i]});
        }
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a.first==b.first) return b.second < a.second;
            return a.first < b.first;
        });

        int ret = 1;
        int right_end = intervals[0].second;
        int farthest_end = intervals[0].second;
        if (right_end >= n) return ret;

        for (int i = 1; i < intervals.size(); i++) {
            if (right_end >= n) break;
            if (intervals[i].first <= right_end) {
                farthest_end = max(farthest_end, intervals[i].second);
            } else {
                if (farthest_end > right_end) {
                    ret++;
                    right_end = farthest_end;
                    i--;
                } else {
                    return -1;
                }
            }
        }
        if (farthest_end > right_end) {
            ret++;
            right_end = farthest_end;
        }
        return ret;
    }
};