//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int>nextSmaller(int *heights,int n)
    {
        stack<int>st;
        st.push(-1);
        // int n=heights.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
             ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(int *heights,int n)
    {
        stack<int>st;
        st.push(-1);
        // int n=heights.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(int *heights,int n) {
        // int n=heights.size();
        vector<int>next(n);
        next=nextSmaller(heights,n);
        vector<int>prev(n);
        prev=prevSmaller(heights,n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(next[i]==-1) next[i]=n;
            mx=max(mx,heights[i]*(next[i]-prev[i]-1));
        }
        return mx;
    }
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        int area=largestRectangleArea(mat[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=0)
                {
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                }
                else mat[i][j]=0;
            }
            area=max(area,largestRectangleArea(mat[i],m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends