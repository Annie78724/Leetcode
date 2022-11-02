class Solution {
public:
    bool isPal(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    void solve(int index,string s,vector<string>& temp,vector<vector<string>>&res)
    {
        if(index==s.size())
        {
            res.push_back(temp);
            return;
        }
        string str="";
        for(int i=index;i<s.size();i++)
        {
            str+=s[i];
            if(isPal(str))
            {
                temp.push_back(str);
                solve(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
    }
};