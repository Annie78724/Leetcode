class Solution {
public:
    void solve(int i,int &x,int &sum,vector<int>& nums)
    {
        if(i==nums.size()){
            sum+=x;
             return ;
        }
        x=x^nums[i];
        solve(i+1,x,sum,nums);
       x=x^nums[i];
        solve(i+1,x,sum,nums);  
        
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0,x=0,i=0;
        solve(i,x,sum,nums);
        return sum;
    }
};