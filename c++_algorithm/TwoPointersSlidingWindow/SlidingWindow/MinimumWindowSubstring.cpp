// https://leetcode.com/problems/minimum-window-substring/
// Minimum Window Substring

// Related questions
// https://leetcode.com/list?selectedList=5qymxb97

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_freq(256, 0);
        vector<int> s_freq(256, 0);
        int num_s = s.size(), num_t = t.size();
        for (auto c : t) t_freq[c]++;
        int slow = 0, fast = 0;
        int count = 0;
        int resStart = -1, resEnd = -1;
        while (fast < num_s) {
            if (t_freq[s[fast]] > 0) {
                s_freq[s[fast]]++;
                if (s_freq[s[fast]] <= t_freq[s[fast]]) {
                    count++;
                }
            }

            while (count == num_t && slow <= fast) {
                if (resStart == -1 || fast - slow + 1 < resEnd - resStart + 1) {
                    resStart = slow; resEnd = fast;
                }
                if (s_freq[s[slow]] > 0) {
                    s_freq[s[slow]]--;
                    if (s_freq[s[slow]] < t_freq[s[slow]]) {
                        count--;
                    }
                }
                slow++;
            }
            fast++;
        }
        if (resStart == -1) return "";
        return s.substr(resStart, resEnd-resStart+1);
    }
};