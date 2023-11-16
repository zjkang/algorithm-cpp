// https://leetcode.com/problems/network-delay-time/
// Q4 Network Delay Time
// single source shortest path

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N , int K) {
        auto buildGraph = [&times, N, K]() {
            map<int, vector<pair<int,int>>> graph;
            for (int i = 0; i < N; i++) {
                graph[i] = {};
            }
            for (auto t : times) {
                graph[t[0]].push_back({t[1], t[2]});
            }
            return graph;
        };
        auto graph = buildGraph();

        // auto pqComp = [](auto l, auto r) {
        //     if (l.first == r.first) {
        //         return l.second > r.second;
        //     }
        //     return l.first > r.first;
        // };
        // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(pqComp)> pq;
        // < == >
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, K});
        set<int> dequeued;
        while (!pq.empty()) {
            auto [weight, node] = pq.top(); pq.pop();
            dequeued.insert(node);
            if (dequeued.size() == N) {
                return weight;
            }
            for (auto [n_n, n_w] : graph[node]) {
                if (dequeued.count(n_n)) {
                    continue;
                }
                pq.push({n_w + weight, n_n});
            }
        }
        return -1;
    }
};