class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>loss;
        for(auto x:matches)
        {
            int w=x[0],l=x[1];
            if(loss[w]==0) loss[w]=0;
            loss[l]++;
        }
        vector<int>a,b;
        for(auto x:loss)
        {
            if(x.second==0)
            {
                a.push_back(x.first);
            }
            else if(x.second==1)
            {
                b.push_back(x.first);
            }
        }
        return {a,b};
    }
};