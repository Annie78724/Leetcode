class Solution {
public:
    unordered_map<string,int>m;
    bool is_unique(string& str)
    {
        int n = str.size();
        vector<int> mp(26, 0);
        
        for(int i = 0; i < n; i++)
        {
            mp[str[i] - 'a']++;
            
            // if we found duplicates return false
            
            if(mp[str[i] - 'a'] > 1)
                return false;
        }
        
        return true;
    }
    void solve(int i,vector<string>& arr,int &ma,string temp)
    {
        if(is_unique(temp) == false)
            return;
        if(i==arr.size()){ 
            if(temp.size() > ma)
            {
                int size = temp.size();
                
                ma = max(ma, size);
            }
            
            return;
        }
            solve(i+1,arr,ma,temp+arr[i]);
            solve(i+1,arr,ma,temp);
        }
    
    int maxLength(vector<string>& arr) {
        int ma=0,i=0;
        string temp="";
        solve(i,arr,ma,temp);
        return ma;
    }
};