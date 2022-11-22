//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int cnt=0;
	    for (int i=0;i<nums.size();i++)
	    {
	        int c1=0,c2=0;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	                c1++;
	        }
	        for(int j=i;j<nums.size();j++)
	        {
	            if(nums[i]<nums[j])
	                c2++;
	        }
	        cnt+=(c1*c2);
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends