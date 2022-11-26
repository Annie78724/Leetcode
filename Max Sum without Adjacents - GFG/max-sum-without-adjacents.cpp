//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int solve(int i,int *arr, int n,vector<int>&dp)
// 	{
// 	    if(i>=n)
// 	    {
// 	        return 0;
// 	    }
// 	    if(dp[i]!=-1) return dp[i];
// 	    int inc=arr[i]+solve(i+2,arr,n,dp);
// 	    int exc=solve(i+1,arr,n,dp);
// 	    return dp[i]=max(inc,exc);
// 	}
	int findMaxSum(int *arr, int n ) {
	    // code here
	    vector<int>dp(n+2,0);
	   // int maxP=solve(0,arr,n,dp);
	   for(int i=n-1;i>=0;i--)
	   {
	    int inc=arr[i]+dp[i+2];
	    int exc=dp[i+1];
	     dp[i]=max(inc,exc);
	   }
	    return dp[0];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends