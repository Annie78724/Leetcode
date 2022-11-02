class Solution {
public:
    void solve(int index,string s,unordered_set<string>&st,string temp,vector<string>&res)
    {
        if(index==s.size())
        {
            temp.pop_back();
            res.push_back(temp);
            return ;
        }
        string substring="";
        for(int i=index;i<s.size();i++)
        {
            substring.push_back(s[i]);
            if(st.count(substring))
            {
                solve(i+1,s,st,temp+substring+" ",res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<string>res;
        string temp="";
        for(auto x:wordDict)
        {
            st.insert(x);
        }
        solve(0,s,st,temp,res);
        return res;
    }
};