class Solution {
public:
    bool isVowel(char c)
    {     if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
     return false;
    }
    bool halvesAreAlike(string s) {
        int i=0;
        int cnt1=0,cnt2=0;
        for( i=0;i<s.size()/2;i++)
        {
            if(isVowel(s[i]))
                cnt1++;
        }
        for(int j=i;j<s.size();j++)
        {
            if(isVowel(s[j]))
                cnt2++;
        }
        return cnt1==cnt2;
    }
};