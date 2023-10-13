// https://leetcode.com/problems/range-addition/
// 370. Range Addition

// 差分数组
// diff[i]表示nums[i]比nums[i-1]大多少。这样如果已知nums[i-1]，
// 那么就有nums[i]=nums[i-1]+diff[i]。
// 本题中的三元参数update(i,j,k)恰好就是给出了这样的差分数组的信息：diff[i]+=k, diff[j+1]-=k

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>diff(length + 1,0);
        for (auto x : updates) {
            diff[x[0]] += x[2];
            diff[x[1] + 1] -= x[2];
        }
        vector<int> results;
        int cur = 0;
        for (int i = 0; i < length; i++) {
            cur += diff[i];
            results.push_back(cur);
        }
        return results;
    }
};