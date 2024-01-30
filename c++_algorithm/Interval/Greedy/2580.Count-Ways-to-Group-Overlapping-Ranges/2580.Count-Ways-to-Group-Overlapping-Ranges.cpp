// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/
// 2580. Count Ways to Group Overlapping Ranges

// sort by starting point and track the farthest right end

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        auto cmp = [](vector<int>& l, vector<int>& r) {
            return l[0] < r[0];
        };
        sort(ranges.begin(), ranges.end(), cmp);

        int count = 1;
        int right_end = ranges[0][1];
        for (int i = 1; i < ranges.size(); i++) {
            if (ranges[i][0] > right_end) {
                count++;
                right_end = ranges[i][1];
            } else {
                right_end = max(right_end, ranges[i][1]);
            }
        }
        // or fast power
        int MOD = 1e9 + 7;
        long long ret = 1;
        int p = 1;
        while (p <= count) {
            ret *= 2;
            ret %= MOD;
            p++;
        }
        return ret;
    }
};


// [1] [2] [3,4], [5]
// group1 2*5
// group2

