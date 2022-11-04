class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        if(s.size()==1) return s;
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isVowel(s[i]) and isVowel(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i]))
                i++;
            else if(!isVowel(s[j]))
                j--;
            
        }
        return s;
    }
};