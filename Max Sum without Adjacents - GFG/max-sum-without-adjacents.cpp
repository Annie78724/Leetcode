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
	    int next1=0,cur=0,next2=0;
	   for(int i=n-1;i>=0;i--)
	   {
	    int inc=arr[i]+next2;
	    int exc=next1;
	     cur=max(inc,exc);
	     next2=next1;
	     next1=cur;
	   }
	    return cur;
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