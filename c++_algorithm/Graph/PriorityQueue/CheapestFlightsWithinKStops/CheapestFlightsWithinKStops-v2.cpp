class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        map<int,vector<pair<int,int>>> graph;
        for (auto x : flights) {
            graph[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, 0, src});
        set<pair<int,int>> dequeued;

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop(); // cannot auto& as the the reference will be removed later
            auto [weight, stop, city] = top;
            if (city == dst) return weight;
            if (dequeued.count({city, stop})) continue;
            dequeued.insert({city, stop});
            if (stop < K + 1) {
                for (auto [n_dst, n_weight] : graph[city]) {
                    if (dequeued.count({n_dst, stop + 1})) continue;
                    pq.push({weight + n_weight, stop + 1, n_dst});
                }
            }
        }
        return -1;
    }
};