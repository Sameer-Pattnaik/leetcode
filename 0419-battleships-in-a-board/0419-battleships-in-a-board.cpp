class Solution {
public:
void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited,int delRow[],int delCol[])
{
    int n=board.size();
    int m=board[0].size();
    visited[row][col]=1;
    for(int i=0;i<4;i++)
    {
        int nRow=row+delRow[i];
        int nCol=col+delCol[i];
        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && board[nRow][nCol]=='X')
        {
            dfs(nRow,nCol,board,visited,delRow,delCol);
        }
    }
}
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j]=='X')
                {
                    cnt++;
                    dfs(i,j,board,visited,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};