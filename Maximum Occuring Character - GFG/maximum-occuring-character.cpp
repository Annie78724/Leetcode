//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26]={0};
        for(auto c:str)
        {
            if(c>='a' and c<='z')
            {
                arr[c-'a']++;
            }
            if(c>='A' and c<='Z')
            {
                arr[c-'A']++;
            }
        }
        int ind=-1,ma=-1;
        for(int i=0;i<26;i++)
        {
            if(ma<arr[i])
            {
                ma=arr[i];
                ind=i;
            }
        }
        // cout<<ind;
        char e=ind+'a';
        return e;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends