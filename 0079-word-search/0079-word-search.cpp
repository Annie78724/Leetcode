class Solution {
public:
    void solve(int i,int j,int k, string &word,int m,int n,vector<vector<char>>& board,bool& f){
        if(k>=word.size())
        {
            f=true;
            return;
        }
        if(i<0 or j<0 or i>=m or j>=n or board[i][j]!=word[k])
            return;
        // cout<<word[k]<<" "<<k<<" ";
        board[i][j]='.';
         solve(i+1,j,k+1,word,m,n,board,f);                                    solve(i-1,j,k+1,word,m,n,board,f);
         solve(i,j+1,k+1,word,m,n,board,f);  
         solve(i,j-1,k+1,word,m,n,board,f);
          board[i][j] = word[k];

    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        int m=board.size(),n=board[0].size(),k=0;
        bool f=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[k])
                {
                            solve(i,j,k,word,m,n,board,f);
                }
            }
        }
        cout<<endl;
        return f;
    }
};