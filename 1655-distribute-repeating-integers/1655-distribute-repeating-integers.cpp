class Solution {
public:
    bool solve(int i,unordered_map<int,int>& m,vector<int>& quantity)
    {
        if(i==quantity.size()) return true;
        for(auto it:m)
        {
            if(it.second>=quantity[i])
            {
                m[it.first]=m[it.first]-quantity[i];
                bool recAns=solve(i+1,m,quantity);
                if(recAns) return true;
                m[it.first]=m[it.first]+quantity[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>m;
        for(auto x:nums)
        {
            m[x]++;
        }
        sort(quantity.begin(),quantity.end(),greater<int>());
        bool ans=solve(0,m,quantity);
        return ans;
    }
};