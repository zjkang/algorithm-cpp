// https://leetcode.com/problems/reconstruct-itinerary/

// Reconstruct itinerary
// TLE error
class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        auto graph = buildGraph(tickets);
        dfs(graph, "JFK", 0, tickets.size());
        return res;
    }

    bool dfs(map<string,vector<string>>& graph, string start, int level, int depth) {
        if (level == depth) {
            res.push_back(start);
            return true;
        }
        if (!graph.count(start) || graph[start].size() == 0) {
            return false;
        }
        res.push_back(start);
        for (int i = 0; i < graph[start].size(); i++) {
            string nei = graph[start][i];
            graph[start].erase(graph[start].begin()+i);
            if (dfs(graph, nei, level+1, depth)) {
                return true;
            }
            graph[start].insert(graph[start].begin()+i, nei);
        }
        res.pop_back();
        return false;
    }

    map<string,vector<string>> buildGraph(vector<vector<string>>& tickets) {
        map<string,vector<string>> graph;
        for (auto& x : tickets) {
            graph[x[0]].push_back(x[1]);
        }
        for (auto& [k,v] : graph) {
            sort(v.begin(), v.end());
        }
        return graph;
    }
};

// https://github.com/wisdompeak/LeetCode/blob/7b9459b0ecf4de647324c8d5a4eb9781aa48daba/DFS/332.Reconstruct-Itinerary/332.Reconstruct-Itinerary_v2.cpp
class Solution {
    unordered_map<string,queue<string>>Map;

public:
    vector<string> findItinerary(vector<vector<string>> tickets)
    {
        sort(tickets.begin(),tickets.end());
        for (auto ticket: tickets)
            Map[ticket[0]].push(ticket[1]);

        vector<string> path;
        DFS("JFK",path);
        reverse(path.begin(),path.end());
        return path;
    }

    void DFS(string start, vector<string>& path)
    {
        while (Map[start].size()>0)
        {
            string nextStart = Map[start].front();
            Map[start].pop();
            DFS(nextStart, path);
        }
        path.push_back(start);
    }
};