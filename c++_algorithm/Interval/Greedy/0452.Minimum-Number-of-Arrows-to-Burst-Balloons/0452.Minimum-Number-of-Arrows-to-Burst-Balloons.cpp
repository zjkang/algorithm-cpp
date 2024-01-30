// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// 452. Minimum Number of Arrows to Burst Balloons

//这道题等价于最多的non-overlapping intervals


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(begin(points), end(points), [](const auto& l, const auto& r) {
            return l[1] < r[1];
        });

        int arrows = 1;
        int cur = points[0][1];
        for (auto& p : points) {
            // If the current balloon starts after the end of another one,
            // one needs one more arrow
            if (cur < p[0]) {
                arrows++;
                cur = p[1];
            }
        }
        return arrows;
    }
};