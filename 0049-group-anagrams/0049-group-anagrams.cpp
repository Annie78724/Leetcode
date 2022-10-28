class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
                m[t].push_back(strs[i]);
        }
        vector<vector<string>>ans(m.size());
        int j=0;
        for(auto x:m)
        {
            for(int i=0;i<x.second.size();i++)
            {
                ans[j].push_back(x.second[i]);
            }
            j++;
        }
        return ans;
    }
};