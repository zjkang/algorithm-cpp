// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, 0);
        int slow = 0, fast = 0;
        int ret = 0;
        while (fast < s.size()) {
            seen[s[fast]]++;
            while (slow <= fast && seen[s[fast]] == 2) {
                seen[s[slow]]--;
                slow++;
            }
            ret = max(ret, fast - slow + 1);
            fast++;
        }
        return ret;
    }
};
