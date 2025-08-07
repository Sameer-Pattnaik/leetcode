class Solution {
private:
    int n;
    int dfs3(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;

        if(memo[row][col] != -1){return memo[row][col];}
        
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs3(row + 1, col + 1, mat));
        }
        else if (row - 1 == col) {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat)});
        }
        else {
            res = max({res,
                       dfs3(row + 1, col + 1, mat),
                       dfs3(row, col + 1, mat),
                       dfs3(row - 1, col + 1, mat)});
        }
        
        return memo[row][col] = val + res;
    }

    int dfs2(int row, int col, vector<vector<int>>& mat) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0;
        if(memo[row][col] != -1){return memo[row][col];}
        int val = mat[row][col];
        int res = 0;

        if (row == col) {
            res = max(res, dfs2(row + 1, col + 1, mat));
        }
        else if (row == col - 1) {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat)});
        }
        else {
            res = max({res,
                       dfs2(row + 1, col + 1, mat),
                       dfs2(row + 1, col, mat),
                       dfs2(row + 1, col - 1, mat)});
        }
        return memo[row][col] = val + res;
    }

public:
    vector<vector<int>> memo;
    int maxCollectedFruits(vector<vector<int>>& mat) {
        n = mat.size();
        int total = 0;
        memo = vector<vector<int>> (n, vector<int> (n, -1));
        for (int i = 0; i < n; i++) {
            total += mat[i][i];
            mat[i][i] = 0;
        }
        total += dfs3(n - 1, 0, mat);
        total += dfs2(0, n - 1, mat);

        return total;
    }
};