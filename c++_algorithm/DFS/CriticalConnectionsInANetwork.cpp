// https://leetcode.com/problems/critical-connections-in-a-network/
// 1192. Critical Connections in a Network

// wisdompeak explanation
// https://github.com/wisdompeak/LeetCode/tree/a929eb56fd1505951d3c7a5566c892015dbba68b/DFS/1192.Critical-Connections-in-a-Network
// 本题本质就是图论中的经典问题，如何求一个无向图中的割边（critical edge）或者叫做桥（bridge）。

// 网上的教程中，我觉得这一篇是最容易理解的：https://www.cnblogs.com/nullzx/p/7968110.html

// 简单地说，我们可以以任意一个未访问过的节点作为根节点，用DFS的顺序来进行搜索，即永远深度优先，
// 然后回溯再搜索其他分支。如果碰到访问过的节点，就停止，保证不行成环。

// 我们在dfs的过程中维护两个数组，一个是dfn[u]，表示节点u被第一次访问时的顺序（可以理解为时间戳），
// 这个是唯一且不变的量。另一个数组low[u]比较关键，初始的时候low[u]=dfn[u]。
// 我们以u为节点的开始dfs（注意抵达u之前可能还有u的父节点，但我们dfs的时候不走回头路），
// 想象它最终形成一棵搜索树，那么u的所有子节点中止的条件不外乎有两个：一个是走进了死胡同；
// 另一个就是遇到了已经访问过的节点，特别的，这个已经访问过的节点有可能是u的祖先节点！所以，有了这样的搜索树之后，
// low[u]可以有机会更新为它所有的子节点v可以接触到的最小时间戳low[v]。

// 令v是u的一个子节点，且有low[v]>dfn[u]，这说明什么呢？说明从v出发最终无法绕道u的前面去。因此(v,u)就是割边。
// 如果消除了这条边，v及其子树就是一个孤岛，无法与u或u的祖先相通。同理，如果low[v]>=dfn[u]，说明u是一个割点，
// 如果消除了这个点，那么v及其子树也是一个孤岛。

// 本题中我们还设置了一个parent，其实是为了标记dfs过程中的搜索顺序。因为无向图for auto v: next[u]的遍历过程中，
// v可能是u的父节点，这种情况下v其实不能作为从u开始dfs的下一个目的地（否则就是走回头路了），所以得排除

class Solution {
public:
    vector<vector<int>> res;
    map<int,vector<int>> graph;
    vector<int> jumps;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto x : connections) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        jumps.resize(n, 0);
        dfs(0, -1, 0);
        return res;
    }

    int dfs(int cur, int parent, int level) {
        if (jumps[cur] > 0) return jumps[cur];
        level++;
        jumps[cur] = level;
        for (auto x : graph[cur]) {
            if (x == parent) continue;
            jumps[cur] = min(jumps[cur], dfs(x, cur, level));
        }
        if (jumps[cur] == level && parent != -1) {
            res.push_back({parent, cur});
        }
        return jumps[cur];
    }
};