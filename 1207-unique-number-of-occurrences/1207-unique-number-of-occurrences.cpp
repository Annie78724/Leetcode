class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        set<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        int a=INT_MIN;
        for(auto x:m)
        {
            ans.insert(x.second);
        }
        return ans.size()==m.size();
    }
};