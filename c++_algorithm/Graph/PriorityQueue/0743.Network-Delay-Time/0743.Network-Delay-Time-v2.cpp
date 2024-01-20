using PI = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N , int K) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<PI, vector<PI>, greater<>> pq;
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