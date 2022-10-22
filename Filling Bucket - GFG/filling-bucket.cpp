//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const int mod=1e8;
    int fillingBucket(int n) {
        // code here
         if(n == 0 || n==1)
            return 1;
        
        int one = 1 , two=1,abhi;
        for(int i=2 ;i<=n ;i++){
            abhi = (one + two)%mod;
            one = two ;
            two = abhi;
        }
        
        return abhi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends