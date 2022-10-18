class Solution {
public:
    int countDigitOne(int n) {
        if(n==0) return 0;
        if(n<10) return 1;
        int len=to_string(n).length();
        int base=pow(10,len-1);
        int firstDigit=n/base;
        int rem=n%base;
            int oneInBase=0;
        if(firstDigit==1)
        {
            oneInBase=n-base+1;
        }
        else
        {
            oneInBase=base;
        }
        return countDigitOne(rem)+firstDigit*countDigitOne(base-1)+oneInBase;
    }
};