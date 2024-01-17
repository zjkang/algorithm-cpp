// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
// 2516. Take K of Each Character From Left and Right

class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = 0, b = 0, c = 0;
        for (char x: s) {
            if (x == 'a') a++;
            if (x == 'b') b++;
            if (x == 'c') c++;
        }

        if (a < k || b < k || c < k) return -1;

        a = a - k;
        b = b - k;
        c = c - k;

        int slow = 0, fast = 0;
        int ca = 0, cb = 0, cc = 0;
        int res = INT_MIN;
        while (fast < s.size()) {
            if (s[fast] == 'a') ca++;
            if (s[fast] == 'b') cb++;
            if (s[fast] == 'c') cc++;
            // shrink when > threshold
            while (slow <= fast && (ca > a || cb > b || cc > c)) {
                if (s[slow] == 'a') ca--;
                if (s[slow] == 'b') cb--;
                if (s[slow] == 'c') cc--;
                slow++;
            }
            res = max(res, fast - slow + 1);
            fast++;
        }

        return s.size() - res;
    }
};