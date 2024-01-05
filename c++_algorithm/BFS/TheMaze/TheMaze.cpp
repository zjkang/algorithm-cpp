// https://leetcode.com/problems/the-maze/
// 490. The Maze


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start[0] == destination[0] && start[1] == destination[1]) return true;
        queue<array<int,2>> queue;
        queue.push({start[0], start[1]});
        auto cmp = [](auto& l, auto& r) {
            if (l[0] == r[0]) return l[1] < r[1];
            return l[0] < r[0];
        };
        set<array<int,2>, decltype(cmp)> visited;
        visited.insert({start[0], start[1]});
        while (!queue.empty()) {
            auto head = queue.front(); queue.pop();
            if (head[0] == destination[0] && head[1] == destination[1]) {
                return true;
            }
            for (auto& nei : getNextValid(head, maze)) {
                if (!visited.count(nei)) {
                    queue.push(nei);
                    visited.insert(nei);
                }
            }
        }
        return false;
    }

    vector<array<int,2>> getNextValid(array<int,2>& cur, vector<vector<int>>& maze) {
        int M = maze.size(), N = maze[0].size();
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        vector<array<int,2>> nextLocs;
        for (int i = 0; i < 4; i++) {
            int cx = cur[0] + dx[i];
            int cy = cur[1] + dy[i];
            while (cx >= 0 && cx < M && cy >= 0 && cy < N && maze[cx][cy] == 0) {
                cx += dx[i];
                cy += dy[i];
            }
            cx -= dx[i];
            cy -= dy[i];
            if (cx != cur[0] || cy != cur[1]) {
                nextLocs.push_back({cx, cy});
            }
        }
        return nextLocs;
    }
};