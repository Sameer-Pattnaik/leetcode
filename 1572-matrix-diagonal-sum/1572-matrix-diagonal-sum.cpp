class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int sum=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int row=0;
        int col=0;
        while(row<n && col<n)
        {
            if(!visited[row][col])
            {
               visited[row][col]=1;
               sum+=mat[row][col];
            }
            row++;
            col++;
        }
        row=n-1;
        col=0;
        while(row>=0 && col<n)
        {
            if(!visited[row][col])
            {
                visited[row][col]=1;
                sum+=mat[row][col];
            }
            row--;
            col++;
        }
        return sum;
    }
};