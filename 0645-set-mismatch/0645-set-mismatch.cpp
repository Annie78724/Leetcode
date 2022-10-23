class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<int>ans(2);
        while(i<n)
        {
            if(nums[i]==i+1)
            {
                i++;
            }
            else
            {
                if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
                else
                {
                    ans[0]=nums[i];
                    ans[1]=(i+1);
                    i++;
                }
            }
        }
        return ans;
    }
};