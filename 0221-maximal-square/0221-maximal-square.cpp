class Solution {
public:
    
    // declare a dp
    
    int dp[305][305];
    
    int dfs(vector<vector<char>>& matrix, int i, int j, int n, int m)
    {
        // base case
        
        if(i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] == '0')
            return 0;
        
        // if already calculated
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // call for right cell
        
        int right = dfs(matrix, i, j + 1, n, m);
        
        // call for down cell
        
        int down = dfs(matrix, i + 1, j, n, m);
        
        // call for digonal cell
        
        int diagonal = dfs(matrix, i + 1, j + 1, n, m);
        
        // return the possible side of square
        
        return dp[i][j] = 1 + min({right, down, diagonal});
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        // initialize the dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        // find the max_area possible
        
        int max_area = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    int curr_side = dfs(matrix, i, j, n, m);
                    
                    int curr_area = curr_side * curr_side;
                    
                    max_area = max(max_area, curr_area);
                }
            }
        }
        
        return max_area;
    }
};