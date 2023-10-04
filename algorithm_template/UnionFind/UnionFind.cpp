
// Union Find template
vector<int>Father;
int N = s.size();
Father.resize(N);
for (int i=0; i<N; i++)
    Father[i] = i;

int FindFather(int x) {
    if (Father[x]!=x)
        Father[x] = FindFather(Father[x]);
    return Father[x];
}

void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x<y)
        Father[y] = x;
    else
        Father[x] = y;
}


// MST
// https://leetcode.com/problems/min-cost-to-connect-all-points/
// 1584. Min Cost to Connect All Points
class Solution {
public:
    // MST
    vector<int>Father;
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> distPoints;
        int N = points.size();
        Father.resize(N);
        for (int i=0; i<N; i++)
            Father[i] = i;
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                auto p1 = points[i];
                auto p2 = points[j];
                int dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                distPoints.push_back({dist, i, j});
            }
        }
        
        sort(distPoints.begin(), distPoints.end(), [](auto& l, auto& r) {
            return l[0] < r[0];
        });
        
        int res = 0;
        int count = 1;
        for (auto p : distPoints) {
            int dist = p[0];
            int p1 = p[1];
            int p2 = p[2];
            
            if (FindFather(p1) != FindFather(p2)) {
                Union(p1, p2);
                res += dist;
                count++;
                if (count == N) break;
            }
        }
        return res;
    }

    int FindFather(int x) {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }
};


// Union Find problems
// https://leetcode.com/problems/number-of-islands-ii/
// 305. Number of Islands II
// calculate individual islands and use union-find to merge connected components




