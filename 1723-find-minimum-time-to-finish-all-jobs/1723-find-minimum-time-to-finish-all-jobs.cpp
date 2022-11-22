class Solution {
public:
    void solve(int i,int k,int n,vector<int>& jobs,vector<int>& work,int &ans)
    {
        if(i==n)
        {
            ans=min(*max_element(work.begin(),work.end()),ans);
            return ;
        }
        if(*max_element(work.begin(),work.end())>ans)
            return;
        for(int j=0;j<k;j++)
        {
            if(j>0 and work[j]==work[j-1]) continue;
            work[j]+=jobs[i];
            solve(i+1,k,n,jobs,work,ans);
            work[j]-=jobs[i];

        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>work(k,0);
        sort(jobs.begin(),jobs.end(),greater<int>());
        int n=jobs.size();
        if(n==k) return jobs[0];
        int ans=INT_MAX;
        int index=0;
        solve(index,k,n,jobs,work,ans);
        return ans;
    }
};