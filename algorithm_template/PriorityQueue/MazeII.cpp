// https://leetcode.com/problems/the-maze-ii/
// 505. The Maze II

// Priority Queue - Custom type
struct State {
    int dist;
    int x;
    int y;
};

struct Comp {
    bool operator()(State l, State r) {
        if (l.dist == r.dist) {
            if (l.x == r.x) return l.y > r.y;
            return l.x > r.x;
        }
        return l.dist > r.dist;
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start[0] == destination[0] && start[1] == destination[1]) return 0;
        priority_queue<State, vector<State>, Comp> pq; // min pq
        pq.push({0, start[0], start[1]});
        set<pair<int,int>> dequeued; // pair type is sorted by default in c++
        while (!pq.empty()) {
            auto state = pq.top(); pq.pop();
            dequeued.insert({state.x, state.y});
            if (state.x == destination[0] && state.y == destination[1]) {
                return state.dist;
            }
            for (auto& s : getNextLocations(maze, state.x, state.y)) {
                if (dequeued.count({s.x, s.y})) continue;
                pq.push({s.dist + state.dist, s.x, s.y});
            }
        }
        return -1;
    }

    vector<State> getNextLocations(vector<vector<int>>& maze, int x, int y) {
        int m = maze.size(), n = maze[0].size();
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        vector<State> nextLocs;
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            int dist = 1;
            while (isInBound(cx, cy, maze) && maze[cx][cy] == 0) {
                cx += dx[i];
                cy += dy[i];
                dist++;
            }
            cx -= dx[i];
            cy -= dy[i];
            dist--;
            if (cx != x || cy != y) {
                nextLocs.push_back({dist, cx, cy});
            }
        }
        return nextLocs;
    }

    bool isInBound(int x, int y , vector<vector<int>>& maze) {
        return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size();
    }
};
