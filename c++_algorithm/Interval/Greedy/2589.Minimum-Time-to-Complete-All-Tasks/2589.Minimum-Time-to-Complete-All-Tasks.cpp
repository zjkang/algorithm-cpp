// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/
// 2589. Minimum Time to Complete All Tasks

// hint: 
// 1. Since there are only up to 2000 time points to consider, you can check them one by one
// 2. It is always beneficial to run the task as late as possible so that later tasks can run simultaneously

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& l, auto& r) {
            if (l[1]==r[1]) return r[0] < l[0];
            return l[1] < r[1];
        });
        // each time spot and allocate to the last spots once available
        vector<int> runs(2001, 0);
        for (int i = 0; i < tasks.size(); i++) {
            auto& task = tasks[i];
            int duration = task[2];
            for (int t = task[0]; t <= task[1]; t++) {
                if (runs[t] != 0) {
                    duration--;
                }
            }
            int t = task[1];
            while (duration > 0) {
                if (runs[t] == 0) {
                    runs[t]++;
                    duration--;
                }
                t--;
            }
        }
        int ret = 0;
        for (int i = 1; i <= 2000; i++) {
            if (runs[i] != 0) ret++;
        }
        return ret;
    }
};