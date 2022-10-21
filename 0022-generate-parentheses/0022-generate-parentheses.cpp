class Solution {
public:
    void solve(string &temp,int cOpen,int cClose,int rOpen,int rClose,vector<string>&ans)
    {
        if(rOpen==0 and rClose==0)
        {
            ans.push_back(temp);
            return;
        }
        if(rOpen>0)
        {
            temp.push_back('(');
            solve(temp,cOpen+1,cClose,rOpen-1,rClose,ans);
            temp.pop_back();
        }
        if(rClose>0 and cOpen>cClose)
        {
            temp.push_back(')');
            solve(temp,cOpen,cClose+1,rOpen,rClose-1,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="(";
        int curOpen=1,curClose=0,remOpen=n-1,remClose=n;
        solve(temp,curOpen,curClose,remOpen,remClose,ans);
        return ans;
    }
};