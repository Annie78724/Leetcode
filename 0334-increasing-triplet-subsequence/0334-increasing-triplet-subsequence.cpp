class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one=INT_MAX,two=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(one>nums[i])
            {
                one=nums[i];
            }
            else if(nums[i]>one and nums[i]<two)
            {
                two=nums[i];
            }
            else if(nums[i]>two)
                return true;
        }
        return false;
    }
};