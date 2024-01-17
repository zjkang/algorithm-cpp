// https://leetcode.com/problems/count-complete-substrings/
// 2953. Count Complete Substrings

// https://github.com/wisdompeak/LeetCode/tree/6e9041b23b6c2c4f62bfe2f20c80e361e5393e51/Two_Pointers/2953.Count-Complete-Substrings
// 参考了群主的题解
// 主要思想是拆分数组，然后对于每个拆分的数组进行sliding window
// window的大小可以有distinct char来确定,滑动窗口是固定大小的

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ret = 0;
        int i = 0;
        while (i < n) {
            int j = i+1;
            while (j<n && abs(word[j]-word[j-1])<=2)
                j++;
            ret += helper(word.substr(i, j-i), k);
            i = j;
        }
        return ret;
    }

    int helper(const string& s, int k) {
        int count = 0;
        set<char>Set(s.begin(), s.end());
        for (int T = 1; T <= Set.size(); T++) {
            int len = T * k;
            vector<int>freq(26,0);
            // fix window size
            int slow = 0, fast = 0;
            while (fast < s.size()) {
                freq[s[fast]-'a']++;
                while (slow <= fast && fast-slow+1 > len) {
                    freq[s[slow]-'a']--;
                    slow++;
                }
                if (fast - slow + 1 == len) {
                    if (check(freq, k)) {
                        count++;
                    }
                }
                fast++;
            }
        }
        return count;
    }

    bool check(vector<int>& freq, int k) {
        for (int x: freq) {
            if (x != k && x != 0) 
                return false;
        }
        return true;
    }
};




