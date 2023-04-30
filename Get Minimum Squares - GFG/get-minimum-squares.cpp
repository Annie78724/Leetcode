//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n)
	{
	     vector<int>dp(n+1,INT_MAX);
	   dp[0]=0;
	    for(int j=1;j<=n;j++)
	    {
	    for(int i=1;i*i<=n;i++)
	    {
	        int temp=i*i;
	        if(j-temp>=0)
	        dp[j]=min(dp[j],1+dp[j-temp]);
	    }
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    // Code here
	   
	    return solve(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends