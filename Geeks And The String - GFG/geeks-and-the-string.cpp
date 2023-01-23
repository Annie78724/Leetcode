//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string rem(string s){
        string ans;int i=0;
        int n=s.size();
        while(i<n)
        {
            if(i<n-1 and s[i]==s[i+1])
            {
                i++;
            }
            else
            {
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
    string removePair(string s) {
        // code here
        string s1;
        while(s.size()!=s1.size())
        {
            s1=s;
            s=rem(s);
        }
        return s.size()==0?"-1":s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends