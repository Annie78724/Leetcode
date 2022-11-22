class Solution {
public:
    int numSquares(int n) {
       int dp[n+1];
        dp[0]=0;
        for(int i=0;i<=n;i++)
        {
            dp[i]=i;
            for(int j=0;j*j<=i;j++)
            {
                int sq=j*j;
                dp[i]=min(dp[i],1+dp[i-sq]);
            }
        }
        return dp[n];
    }
};