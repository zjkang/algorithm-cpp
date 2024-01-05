// https://leetcode.com/problems/minimum-cost-to-convert-string-ii/
// 2977. Minimum Cost to Convert String II

// 1. str -> index: then do Floyd algorithm
// 2. missing on corner case: when source[i] == target[i]: the min cost can be
//    min(dp[i], dp[i-1])
// 3. TLE/MLE: search from lenth set to avoid invalid search


class Solution {
public:
    using LL = long;
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_set<string> set;
        set.insert(original.begin(), original.end());
        set.insert(changed.begin(), changed.end());

        int idx = 0;
        unordered_map<string, int> map;
        for (auto& s : set) {
            map[s] = idx;
            idx++;
        }

        int n = map.size();
        LL d[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = LONG_MAX;
                }
            }
        }

        for (int i = 0; i < original.size(); i++) {
            d[map[original[i]]][map[changed[i]]] = min(
                d[map[original[i]]][map[changed[i]]],
                (LL)cost[i]);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k] != LONG_MAX && d[k][j] != LONG_MAX) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }

        unordered_set<int> len_set;
        for (auto& s : original) {
            len_set.insert(s.size());
        }

        int m = source.size();
        LL dp[m];
        for (int i = 0; i < m; i++)
            dp[i] = LONG_MAX;

        for (int i = 0; i < m; i++) {
            // missing: special case
            if (source[i] == target[i]) {
                dp[i] = min(dp[i], (i-1 < 0 ? 0 : dp[i-1])); 
            }
            // search from the len set as there are only 100 different lengths as most
            for (int l: len_set) {
                int j = i-l+1;
                if (j >= 0) {
                    const string& s = source.substr(j, i-j+1);
                    const string& t = target.substr(j, i-j+1);
                    int idx_s = map.find(s) != map.end() ? map[s] : -1;
                    int idx_t = map.find(t) != map.end() ? map[t] : -1;

                    if (idx_s == -1 || idx_t == -1) continue;
                    if (j-1>=0 && dp[j-1]==LONG_MAX) continue;
                    if (d[idx_s][idx_t] == LONG_MAX) continue;
                    dp[i] = min(dp[i], (j-1 < 0 ? 0 : dp[j-1])+d[idx_s][idx_t]);
                }
            }
        }

        if (dp[m-1] == LONG_MAX) return -1; // missing
        return dp[m-1];
    }
};