class Solution {
public:
bool isValid(vector<vector<char>>&board,int row,int col,char k)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==k)
            {
                return false;
            }
            if(board[row][i]==k)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==k)
            {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                        
                        if(isValidSudoku(board))
                        {
                           return true; 
                        }
                        else{
                      board[i][j]='.';
                        }
                        }
                    }
                  return false;  
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        isValidSudoku(board);
    }
    
};