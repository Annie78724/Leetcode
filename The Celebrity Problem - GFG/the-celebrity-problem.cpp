//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(m[a][b]==1)
            {
                st.push(b);
            }
            else if(m[b][a]==1)
            {
                st.push(a);
            }
        }
        int celb=st.top();
        bool rowflag=false;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            if(m[celb][i]==0)zero++;
        }
        if(zero==n) rowflag=true;
        bool colflag=false;
        int one=0;
        for(int i=0;i<n;i++)
        {
            if(m[i][celb]==1)one++;
        }
        if(one==n-1) colflag=true;
        return rowflag&&colflag?celb:-1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends