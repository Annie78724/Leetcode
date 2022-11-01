class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n)
    {
        int i=row,j=col;
        while(j>=0){
            if(board[row][j]=='Q') return false;
            j--;
        }
        i=row,j=col;
        while(i>=0 and j>=0)
        {
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i<n and j>=0)
        {
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>&board,int n,int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';
                solve(ans,board,n,col+1);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
         vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i].push_back('.');
            }
        }
        int col=0;
        solve(ans,board,n,col);
        return ans;
    }
};