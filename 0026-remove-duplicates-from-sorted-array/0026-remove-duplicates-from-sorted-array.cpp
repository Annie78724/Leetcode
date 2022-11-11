class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        nums.clear();
        for(auto x:m)
        {
            nums.push_back(x.first);
        }
        return m.size();
    }
};