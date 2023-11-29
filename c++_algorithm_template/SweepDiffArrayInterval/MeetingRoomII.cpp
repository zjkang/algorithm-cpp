// https://leetcode.com/problems/meeting-rooms-ii/
// 253. Meeting Rooms II

// sweep line general template
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int>> points;
        for (auto x : intervals) {
            points.push_back({x[0], 1}); // start point
            points.push_back({x[1], -1}); // end point
        }
        sort(points.begin(), points.end());
        int on_going = 0;
        int ret = 0;
        int i = 0;
        while (i < points.size()) {
            int time = points[i][0];
            while (i < points.size() && points[i][0] == time) {
                if (points[i][1] == 1) on_going++;
                else on_going--;
                i++;
            }
            ret = max(ret, on_going);
        }
        return ret;
    }
};