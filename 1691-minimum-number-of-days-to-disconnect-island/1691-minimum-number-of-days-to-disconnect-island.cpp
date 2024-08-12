class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid,int delRow[],int delCol[])
    {
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
           int nRow=row+delRow[i];
           int nCol=col+delCol[i];
           if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol]==1)
           {
            dfs(nRow,nCol,visited,grid,delRow,delCol);
           }
        }
    }
    int no_of_Island(vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    cnt++;
                    dfs(i,j,visited,grid,delRow,delCol);

                }
            }
        }
        
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int island=no_of_Island(grid);
        int n=grid.size();
        int m=grid[0].size();
        if(island!=1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    int land=no_of_Island(grid);
                    if(land!=1)
                    {
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};