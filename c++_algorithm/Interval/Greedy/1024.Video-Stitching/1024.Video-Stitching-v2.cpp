// https://leetcode.com/problems/video-stitching/
// 1024. Video Stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](auto& l, auto& r) {
            if (l[0] == r[0]) return r[1] < l[1];
            return l[0] < r[0];
        });
        // corner case
        if (clips[0][0] > 0) return -1;
        int farthest_end = clips[0][1];
        if (farthest_end>=time) return 1;

        int i = 0;
        int N = clips.size();
        int ret = 1;
        while (i < N) {
            int j = i + 1;
            int right_end = farthest_end;
            while (j < N) {
                if (clips[j][0] > right_end) break;
                farthest_end = max(farthest_end, clips[j][1]);
                j++;
            }
            if (farthest_end == right_end) {
                return -1;
            }

            ret++;
            if (farthest_end >= time) {
                return ret;
            }
            i = j-1;
        }
        return ret;
    }
};