// https://leetcode.com/problems/sum-of-subarray-minimums/
// 907. Sum of Subarray Minimums

// 维护单调递增栈
// 维护一个以idx为最小值中心的向左右扩展的子数组

using LL = long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        stack<int> stack; // increasing stack
        LL ret = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.top()] > arr[i]) {
                int idx = stack.top(); stack.pop();
                LL right = i - idx;
                LL left = idx - (stack.empty() ? -1 : stack.top());
                ret += (left * right * arr[idx]) % MOD;
                ret %= MOD;
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int idx = stack.top(); stack.pop();
            LL right = n - idx;
            LL left = idx - (stack.empty() ? -1 : stack.top());
            ret += (left * right * arr[idx]) % MOD;
            ret %= MOD;
        }
        return ret;
    }
};