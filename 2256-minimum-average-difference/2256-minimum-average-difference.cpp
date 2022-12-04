class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum=0,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        long long s1=0,s2=sum,mn=INT_MAX,index=0;
        for(int i=0;i<n;i++)
        {
            s1+=nums[i];
            s2-=nums[i];
            long long a=(s1/(i+1));
           long long b = (i == n-1) ? 0 : s2 / (n-i-1); // average of the last n - i - 1 elements.
            
            if (abs(a-b) < mn) {
                mn = abs(a-b);
                index = i;
            }
        }
        return index;
    }
};