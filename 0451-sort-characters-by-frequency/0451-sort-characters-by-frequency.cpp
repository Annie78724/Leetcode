class Solution {
public:
    string frequencySort(string st) {
        string s="";
        map<char,int>m;
        for(auto c:st)
        {
            m[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty())
        {
            char c=pq.top().second;
            int x=pq.top().first;
            for(int i=0;i<x;i++)
            {
                s+=c;
            }
            pq.pop();
        }
        return s;
    }
};