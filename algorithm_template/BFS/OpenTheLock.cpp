// https://leetcode.com/problems/open-the-lock/
// 752. Open the Lock


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;

        queue<string> queue;
        queue.push("0000");
        set<string> visited;
        int depth = 0;

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                auto cur = queue.front(); queue.pop();
                if (cur == target) return depth;

                for (int ii = 0; ii < 4; ii++) {
                    vector<int> nextDigit = {
                        (cur[ii] - '0' - 1 + 10) % 10, 
                        (cur[ii] - '0' + 1) % 10};
                    for (auto x : nextDigit) {
                        auto next = cur;
                        next[ii] = x + '0';
                        if (!visited.count(next) && !deadSet.count(next)) {
                            visited.insert(next);
                            queue.push(next);
                        }
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};