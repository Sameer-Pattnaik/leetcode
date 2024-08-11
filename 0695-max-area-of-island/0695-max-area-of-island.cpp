class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<int>&ans,int &count,int delRow[],int delCol[])
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        
        for(int i=0;i<4;i++)
        {
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !visited[nRow][nCol] && grid[nRow][nCol]==1)
            {
                count++;
                dfs(nRow,nCol,grid,visited,ans,count,delRow,delCol);
            }
            
        }
        
        ans.push_back(count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       int delRow[]={-1,0,1,0};
       int delCol[]={0,1,0,-1};
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            int count=0;
            if(!visited[i][j] && grid[i][j]==1)
            {
                count++;
                dfs(i,j,grid,visited,ans,count,delRow,delCol);
            }
        }
       }
       int maxIsland=INT_MIN;
       for(int i=0;i<ans.size();i++)
       {
           maxIsland=max(maxIsland,ans[i]);
       }
       if(ans.size()==0)
       {
        return 0;
       }
       return maxIsland;
    }
};