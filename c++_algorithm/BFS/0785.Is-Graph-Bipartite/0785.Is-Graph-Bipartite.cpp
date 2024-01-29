// https://leetcode.com/problems/is-graph-bipartite/
// 785. Is Graph Bipartite?

// neighbor color is the same or not
// find if neighbor color is populated or not or any conflict

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> colorMap;
        for (int i = 0; i < graph.size(); i++) {
            if (colorMap.count(i)) {
                continue;
            }
            colorMap[i] = 0;
            queue<int> queue;
            queue.push(i);
            while (!queue.empty()) {
                auto cur = queue.front(); queue.pop();
                int color = colorMap[cur];
                for (auto nei : graph[cur]) {
                    if (!colorMap.count(nei)) {
                        queue.push(nei);
                        colorMap[nei] = 1 - color;
                    } else {
                        if (colorMap[nei]==color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};