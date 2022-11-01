class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int k)
    {
         for(int i=0;i<9;i++)
         {
             if(board[i][col]=='0'+k) return false;
             if(board[row][i]==k+'0') return false;
             if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==k+'0')
                 return false;
         }
        return true;
    }
     bool solve(vector<vector<char>>& board)
     {
         for(int i=0;i<9;i++)
         {
             for(int j=0;j<9;j++)
             {
                 if(board[i][j]=='.')
                 {
                     for(int k=1;k<=9;k++)
                     {
                         if(isSafe(board,i,j,k))
                         {
                             board[i][j]=k+'0';
                             bool recAns=solve(board);
                             if(recAns) return true;
                             board[i][j]='.';
                         }
                     }
                     return false;
                 }
             }
         }
         return true;
     }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};