class Solution {
public:
    void permute(int i,string &temp,int &cnt,unordered_map<string,int>&m)
    {
        if(i==temp.size())
        {
            if(!m[temp])
           {    
                m[temp]=1;
                // cout<<temp<<" ";
                cnt++;
            }
        }
        for(int j=i;j<temp.length();j++)
        {
            swap(temp[i],temp[j]);
            permute(i+1,temp,cnt,m);
            swap(temp[i],temp[j]); 
        }
    }
    void solve(int i , int &cnt , string &temp , string &s, unordered_map<string,int>&m)
    {
        if(i==s.size())
        {
            if(temp.size()>0 and !m[temp])
            {
                m[temp]=1;
                // cout<<temp<<" ";
                permute(0,temp,cnt,m);
                cnt++;
            }
            return;
        }
        temp.push_back(s[i]);
        solve(i+1,cnt,temp,s,m);
        temp.pop_back();
        solve(i+1,cnt,temp,s,m);
    }
    int numTilePossibilities(string tiles) {
        unordered_map<string,int>m;
         int cnt=0,i=0;
        string temp="";
        solve(i,cnt,temp,tiles,m);
        return cnt;
    }
};