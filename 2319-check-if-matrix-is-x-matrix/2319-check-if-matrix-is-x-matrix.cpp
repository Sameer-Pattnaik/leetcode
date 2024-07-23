class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
       int row=0;
       int col=0;
       while(row<n && col<n)
       {
        if(grid[row][col]==0)
        {
            return false;
        }
        visited[row][col]=1;
        row++;
        col++;
       }
       row=n-1;
       col=0;
       while(row>=0 && col<n)
       {
        if(grid[row][col]==0)
        {
            return false;
        }
        visited[row][col]=1;
        row--;
        col++;
       }
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] && grid[i][j]!=0)
            {
                 return false;
            }
        }
       }
       return true;   
    }
};