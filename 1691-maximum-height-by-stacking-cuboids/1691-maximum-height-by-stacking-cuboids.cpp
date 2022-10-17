class Solution {
public:
    int dp[110][110];
    bool isSafe(vector<vector<int>>& cuboids,int cur,int prev)
    {
            if(cuboids[cur][0]<=cuboids[prev][0] and cuboids[cur][1]<=cuboids[prev][1] and cuboids[cur][2]<=cuboids[prev][2])
            return true;
        return false;
    }
    int solve(vector<vector<int>>& cuboids,int n,int cur,int prev)
    {
        if(cur<0) return 0;
        if(dp[cur][prev+1]!=-1)
        {
            return dp[cur][prev+1];
        }
//         include
        int pick=0;
        if(prev==-1 or isSafe(cuboids,cur,prev))
        {
            pick=cuboids[cur][2]+solve(cuboids,n,cur-1,cur);
        }
        int notPick=solve(cuboids,n,cur-1,prev);
        return dp[cur][prev+1]=max(pick,notPick);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<cuboids.size();i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        int ans=solve(cuboids,n,n-1,-1);
        return ans;
    }
};