class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int s=0,pre=0;
        for(int i=0;i<nums.size();i++)
        {
            s=(s+nums[i])%k;
            if(m[s]) return true;
            m[pre]++;
            pre=s;
        }
        return false;
    }
};