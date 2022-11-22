class Solution {
public:
    int getMinInvalid(string s)
    {
        stack<int>st;
        for(auto c:s)
        {
            if(c=='(')
            {
                st.push(c);
            }
            else if(c==')')
            {
                if(!st.empty() and st.top()=='(')
                    st.pop();
                else
                {
                    st.push(')');
                }
            }
        }
        return st.size();
    }
    void solve(string s,int k,vector<string>&ans,unordered_map<string,bool>&m)
    {
        if(m[s]==true)
        {
            return;
        }
        else
        {
            m[s]=true;
        }
        if(k==0)
        {
            if(getMinInvalid(s)==0)
                ans.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,k-1,ans,m);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        unordered_map<string,bool>m;
        int k=getMinInvalid(s);
        solve(s,k,ans,m);
        return ans;
    }
};