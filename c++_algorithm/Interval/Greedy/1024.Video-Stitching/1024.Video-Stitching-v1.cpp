// https://leetcode.com/problems/video-stitching/
// 1024. Video Stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(clips.begin(), clips.end(), cmp);
        clips.insert(clips.begin(), {0,0}); // insert the first value

        int n = clips.size();
        vector<vector<int>> dp(n, vector<int>(time+1, INT_MAX/2));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= time; j++) {
                dp[i][j] = dp[i-1][j];
                if (clips[i][0] <= j && clips[i][1] >= j) {
                    dp[i][j] = min(1+dp[i-1][clips[i][0]], dp[i][j]);
                }
            }
        }
        if (dp[n-1][time] >= INT_MAX/2) return -1;
        return dp[n-1][time];
    }
};