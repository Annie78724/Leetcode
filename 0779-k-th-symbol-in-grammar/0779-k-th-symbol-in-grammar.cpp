class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int parent=kthGrammar(n-1,k/2+k%2);
        int ans;
        if(parent ==0)
        {
            if(k&1)
            {
                ans=0;
            }
            else
            {
                ans=1;
            }
        }
        else if(parent==1)
        {
            if(k&1)
            {
                ans=1;
            }
            else
            {
                ans=0;
            }
        }
        return ans;
    }
};