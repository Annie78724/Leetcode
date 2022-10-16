class Solution {
public:
    int solve(vector<int>& slices,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(n==0 or i>j) return 0;
        if(dp[i][n] != -1)
            return dp[i][n];
        int inc=slices[i]+solve(slices,i+2,j,n-1,dp);
        int exc=0+solve(slices,i+1,j,n,dp);
        return dp[i][n]= max(inc,exc);
    }
    int maxSizeSlices(vector<int>& slices) {
        int totalSize=slices.size();
        int k=totalSize/3;
         vector<vector<int>> dp1(totalSize + 1, vector<int>(k + 1, -1));
        int option1=solve(slices,0,slices.size()-2,totalSize/3,dp1); 
         vector<vector<int>> dp2(totalSize + 1, vector<int>(k + 1, -1));
        int option2=solve(slices,1,slices.size()-1,totalSize/3,dp2);
        return max(option1,option2);
    }
};