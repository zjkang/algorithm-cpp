// https://leetcode.com/problems/course-schedule/

// method 1: topo sort

// method 2: find cycle in course-schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        auto buildGraph = [](vector<vector<int>>& prerequisites) {
            map<int, vector<int>> graph;
            for (auto x : prerequisites) {
                int u = x[0], v = x[1];
                graph[v].push_back(u);
            }
            return graph;
        };

        function<bool(int, map<int, vector<int>>&, vector<int>&)> isCycle = 
            [&](auto course, auto& graph, auto& visited) { // must use & with reference to isCycle function
            if (visited[course] == 1) return false;
            if (visited[course] == 0) return true;
            visited[course] = 0;
            for (auto i : graph[course]) {
                if (isCycle(i, graph, visited)) {
                    return true;
                }
            }
            visited[course] = 1;
            return false;
        };

        auto graph = buildGraph(prerequisites);
        vector<int> visited(numCourses, -1);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == -1 && isCycle(i, graph, visited)) {
                return false;
            }
        }
        return true;
    }
};
