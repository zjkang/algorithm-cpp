// https://leetcode.com/problems/tree-diameter/
// 1245. Tree Diameter

// 对于一张无向图的树，求最长的点到点距离，有一个非常成熟的做法。
// 我们可以任意取一点A，用BFS找到距离A最远的节点B。那么B一定是就是“最长的点到点距离”的其中一个点。
// 然后我们再以B为起点，用BFS找到距离B最远的节点C。那么BC就是答案。

// 证明：从任意点A开始，能够到达的最远的距离是B。另外，整张图里“最长的点到点距离”是S和T。
// 我们要证明B只可能是S或者T中的一点。如果不是，那么分情况讨论：

// AB与ST完全不相交。那么我们从A找一条路径能够到达ST的路径，并令交点是X。
// 因为AB是从A起始的最长路径，那么AB>AX+XT. 那么我们观察路径B->A->X->S，其距离BA+AX+XS > 2*AX+XT+XS > 2*AX+ST > ST，
// 这就与ST是全局“最长的点到点距离”矛盾。
// AB与ST相交于X。因为AB是从A起始的最长路径，那么AX+XB>AX+XS，即XB>XS. 我们观察路径B->X->T，
// 其距离BX+XT > XS+XT = ST，这就与ST是全局“最长的点到点距离”矛盾

class Solution {
    vector<vector<int>>adj;
    int V;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        V = edges.size()+1;
        adj.resize(V);
        for (auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        auto t1 = bfs(0);
        auto t2 = bfs(t1.first);
        return t2.second;
    }

    pair<int, int> bfs(int u) {
        vector<int>dis(V, -1);
        queue<int> q;
        q.push(u);
        dis[u] = 0;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto it = adj[t].begin(); it != adj[t].end(); it++) {
                int v = *it;
                if (dis[v] == -1) {
                    q.push(v);
                    dis[v] = dis[t] + 1;
                }
            }
        }

        int maxDis = 0;
        int nodeIdx;

        for (int i = 0; i < V; i++) {
            if (dis[i] > maxDis) {
                maxDis = dis[i];
                nodeIdx = i;
            }
        }
        return make_pair(nodeIdx, maxDis);
    }
};