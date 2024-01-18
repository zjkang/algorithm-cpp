// https://leetcode.com/problems/course-schedule/
// 207. Course Schedule

// top排序有的时候和dfs的找环等价
// 这道题可以使用topo来写，另外一种方式是使用dfs找环
// 这道题的dfs找环的解法需要visited的tag有两个值
// visiting表示这个点已经访问，但是由这点扩展出来的connected component还没有全部完成
// visited表示这个点以及扩展出来的connected component已经全部完成

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
