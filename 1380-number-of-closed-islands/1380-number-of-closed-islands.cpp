class Solution {
public:
    void dfs1(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid,int delRow[],int delCol[])
    {
        visited[row][col]=1;
        grid[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol]==0)
            {
                dfs1(nRow,nCol,visited,grid,delRow,delCol);
            }
        }
    }
     void dfs2(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid,int delRow[],int delCol[])
    {
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol]==0)
            {
                dfs2(nRow,nCol,visited,grid,delRow,delCol);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0 && !visited[i][0])
            {
                dfs1(i,0,visited,grid,delRow,delCol);
            }
            if(grid[i][m-1]==0 && !visited[i][m-1])
            {
                dfs1(i,m-1,visited,grid,delRow,delCol);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==0 && !visited[0][i])
            {
                dfs1(0,i,visited,grid,delRow,delCol);
            }
            if(grid[n-1][i]==0 && !visited[n-1][i])
            {
                dfs1(n-1,i,visited,grid,delRow,delCol);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && !visited[i][j])
                {
                    cnt++;
                    dfs2(i,j,visited,grid,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};