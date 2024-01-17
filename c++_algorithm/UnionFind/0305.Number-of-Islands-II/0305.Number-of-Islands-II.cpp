// https://leetcode.com/problems/number-of-islands-ii/
// 305. Number of Islands II

// calculate individual islands and use union-find to merge connected components

// 设置所有点的初始Father为-1，表示海洋。
// 然后依次遍历每一块新陆地，最开始标记它的Root为自身，然后count++。
// 依次考察这个新陆地相邻的四块：如果相邻的是陆地，并且新陆地和老陆地的Root不同，
// 那么说明这是需要合并的两个集合，于是count--，并且将新陆地与旧陆地进行Union。最终实时输出count。

// 有一个corner case是，positions里面可能会包含重复的同一块陆地。
// 所以每遍历一块新陆地的时候，得先看看是否已经访问过了，已经访问过了就不要再重新标记Root，否则会出错。

class Solution {
    vector<int> Father;
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        Father.resize(m * n);
        for (int i = 0; i < m * n; i++) {
             Father[i] = -1;
        }

        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;
        vector<int> result;

        for (int i = 0; i < positions.size(); i++) {
            int x = positions[i][0];
            int y = positions[i][1];
            if (Father[x * n + y] != -1) {
                result.push_back(result.back());
                continue;
            }

            Father[ x * n + y] = x * n + y;
            count += 1;

            for (int k=0; k<4; k++) {
                int a = x + dir[k].first;
                int b = y + dir[k].second;
                if (a < 0 || a >= m || b < 0 || b >= n) {
                    continue;
                }
                if (Father[ a * n + b] == -1) {
                    continue;
                }
                if (Find(a * n + b)!=Find(x * n + y)) {
                    count--;
                    Union(a * n + b, x * n + y);
                }
            }
            result.push_back(count);
        }

        return result;
    }

    int Find(int x) {
        if (x != Father[x]) {
            Father[x] = Find(Father[x]);
        }
        return Father[x];
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x < y) {
            Father[y]=x;
        } else {
            Father[x]=y;
        }
    }
};