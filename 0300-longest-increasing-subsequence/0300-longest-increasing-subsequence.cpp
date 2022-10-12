class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=INT_MAX;
        }
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int idx=upper_bound(dp,dp+n+1,nums[i])-dp;
            if(dp[idx]>nums[i] and dp[idx-1]<nums[i])
            {
                dp[idx]=nums[i];
            }
        }
        int ma=0;
        for(int i=n;i>=0;i--)
        {
            if(dp[i]!=INT_MAX)
            {
                ma=i;
                break;
            }
        }
        return ma;
    }
};