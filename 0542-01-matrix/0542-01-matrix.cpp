class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int>>distance(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    visited[i][j]=1;
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        while(!q.empty())
        {
           int row=q.front().first.first;
           int col=q.front().first.second;
           int dist=q.front().second;
           q.pop();
           distance[row][col]=dist;
           for(int i=0;i<4;i++)
           {
              int nRow=row+delRow[i];
              int nCol=col+delCol[i];
              if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol]==1 && !visited[nRow][nCol])
              {
                visited[nRow][nCol]=1;
                q.push(make_pair(make_pair(nRow,nCol),dist+1));
              }
           }
        }
        return distance;
    }
};