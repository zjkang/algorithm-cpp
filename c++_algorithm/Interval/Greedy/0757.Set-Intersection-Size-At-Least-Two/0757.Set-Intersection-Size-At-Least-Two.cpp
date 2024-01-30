https://leetcode.com/problems/set-intersection-size-at-least-two/
757. Set Intersection Size At Least Two

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto cmp = [](auto& a, auto& b) {
            if (a[1] == b[1]) {
              return a[0] > b[0]; // (3,5), (2,5)
            }
            return a[1] < b[1];      
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int a = intervals[0][1]-1, b = intervals[0][1];
        int ret = 2;

        for (auto& interval: intervals) {
            if (interval[0] <= a) {
                continue;
            }
            if (interval[0] <= b) {
                ret++;
                a = b;
                b = interval[1];
            } else {
                ret += 2;
                a = interval[1]-1;
                b = interval[1];
            }
        }
        return ret;
    }
};