// https://leetcode.com/problems/alien-dictionary/
// 269. Alien Dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, int> indegrees;
        for (auto w : words) {
            for (char c : w) {
                indegrees[c] = 0;
            }
        }
        map<char, vector<char>> edges;
        for (int i = 1; i < words.size(); i++) {
            auto& w1 = words[i-1];
            auto& w2 = words[i];
            int len = min(w1.size(), w2.size());
            int j = 0;
            for (; j < len; j++) {
                if (w1[j] != w2[j]) {
                    indegrees[w2[j]]++;
                    edges[w1[j]].push_back(w2[j]);
                    break;
                }
            }
            if (j == len && j < w1.size()) return ""; // add extra check for "abc" < "ab"
        }

        queue<char> queue;
        for (auto [k,v] : indegrees) {
            if (indegrees[k] == 0) {
                queue.push(k);
            }
        }

        string res;
        while (!queue.empty()) {
            char c = queue.front(); queue.pop();
            res.push_back(c);
            for (auto nei : edges[c]) {
                indegrees[nei]--;
                if (indegrees[nei] == 0) {
                    queue.push(nei);
                }
            }
        }

        if (indegrees.size() == res.size()) {
            return res;
        }
        return "";
    }
};