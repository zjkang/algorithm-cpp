// https://leetcode.com/problems/course-schedule/
// 207. Course Schedule

// topo sort bfs

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> outdegreeMap;
        for (auto& p: prerequisites) {
            indegrees[p[0]]++;
            outdegreeMap[p[1]].push_back(p[0]);
        }
        queue<int> queue;
        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                queue.push(i);
            }
        }

        vector<int> ret;
        while (!queue.empty()) {
            int c = queue.front(); queue.pop();
            ret.push_back(c);
            for (auto x: outdegreeMap[c]) {
                indegrees[x]--;
                if (indegrees[x] == 0) {
                    queue.push(x);
                }
            }
        }

        return ret.size() == numCourses;
    }
};