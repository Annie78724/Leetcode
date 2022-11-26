class Solution {
public:
    // int solve(vector<int>& coins, int amount,vector<int>&dp){
    //     if(amount==0) return 0;
    //     if(amount<0) return INT_MAX;
    //     if(dp[amount]!=-1) return dp[amount];
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++)
    //     {
    //         int ans=solve(coins,amount-coins[i],dp);
    //         if(ans!=INT_MAX)
    //         mini=min(mini,1+ans);
    //     }
    //     return dp[amount]=mini;
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        int mini=INT_MAX;
        for(int am=1;am<=amount;am++)
        {
                    int mini=INT_MAX;
            for(int i=0;i<coins.size();i++)
        {
                if(am-coins[i]>=0)
                {
                     int ans=dp[am-coins[i]];
            if(ans!=INT_MAX)
            mini=min(mini,1+ans);
                }
        }
            dp[am]=mini;
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};