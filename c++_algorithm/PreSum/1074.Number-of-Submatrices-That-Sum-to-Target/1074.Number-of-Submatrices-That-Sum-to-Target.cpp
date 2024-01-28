// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// 1074. Number of Submatrices That Sum to Target

// 这道题将2维的区间和转化为求row1和row2之间的区间和，也就是可以看作一个压缩的1维presum区间和问题。
// 一旦这个转化实现，也就变成了常规的求一个区间和的存在个数问题

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        int ret = 0;
        for (int r1 = 0; r1 < M; r1++) {
            vector<int> presum(N, 0); // prefix sum between r1 and r2
            for (int r2 = r1; r2 < M; r2++) {
                int cur = 0;
                for (int j = 0; j < N; j++) {
                    cur += matrix[r2][j];
                    presum[j] += cur;
                }
                unordered_map<int,int> value_to_count;
                value_to_count[0] = 1;
                for (int j = 0; j < N; j++) {
                    if (value_to_count.count(presum[j] - target)) {
                        ret += value_to_count[presum[j] - target];
                    }
                    value_to_count[presum[j]]++;
                }
            }
        }
        return ret;
    }
};