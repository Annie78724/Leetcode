//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,int n,vector<vector<int>>&m,vector<vector<int>>&vis)
    {
        if((x>=0 and x<n)and (y>=0 and y<n) and vis[x][y]==0 and m[x][y]==1) return true;
        return false;
    }
    void solve(vector<vector<int>>&m,int n,int x,int y,string path,vector<vector<int>>vis, vector<string>&ans)
    {
        if(x==n-1 and y==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[x][y]=1;
        if(isSafe(x+1,y,n,m,vis))
        {
            path.push_back('D');
            // cout<<"Go";
            solve(m,n,x+1,y,path,vis,ans);
            path.pop_back();
        }
        if(isSafe(x,y-1,n,m,vis))
        {
            path.push_back('L');
            // cout<<"Go";
            solve(m,n,x,y-1,path,vis,ans);
            path.pop_back();
        }
        if(isSafe(x-1,y,n,m,vis))
        {
            path.push_back('U');
            // cout<<"Go";
            solve(m,n,x-1,y,path,vis,ans);
            path.pop_back();
        }
        if(isSafe(x,y+1,n,m,vis))
        {
            path.push_back('R');
            // cout<<"Go";
            solve(m,n,x,y+1,path,vis,ans);
            path.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==0) return ans;
        int x=0,y=0;
        string path="";
        solve(m,n,x,y,path,vis,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends