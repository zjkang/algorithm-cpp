// https://leetcode.com/problems/k-inverse-pairs-array/
// 629. K Inverse Pairs Array


class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        const int mod = 1e9 + 7;
        
        for (int i=1; i<=n; i++)
            dp[i][0]=1;
        
        for (int i=2; i<=n; i++)
         for (int j=1; j<=k; j++)
         {
            if (j>=i)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-i])%mod;
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                
            if (dp[i][j]<0)
                dp[i][j]+=mod;
         }
        
        return dp[n][k];
    }
};