class Solution {
public:
 void addToResult(vector<vector<int>>&ans,vector<vector<int>>&board,int n)
 {
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
 }
    bool isSafe(vector<vector<int>>&ans,vector<vector<int>>&board,int col,int row,int n)
    {
        int x=row;
        int y=col;
        while(y>=0)
        {
            if(board[x][y]==1)
            {
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0)
        {
            if(board[x][y]==1)
            {
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n && y>=0)
        {
            if(board[x][y]==1)
            {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<int>>&ans,vector<vector<int>>&board,int col,int n)
    {
        if(n==col)
        {
            addToResult(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(ans,board,col,row,n))
            {
                board[row][col]=1;
                solve(ans,board,col+1,n);
                board[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
       vector<vector<int>>ans;
       vector<vector<int>>board(n,vector<int>(n,0));
       int col=0;
       solve(ans,board,col,n);
       return ans.size(); 
    }
};