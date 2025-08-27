class Solution {
public:
    int n, m;
    vector<int> dx = {-1, 1, 1, -1};
    vector<int> dy = {1, 1, -1, -1};
    int f(int x, int y, int dirNo, int turns, vector<vector<int>>& grid){
        int maxi = 1, nx, ny, val, newTurns;
        nx = x + dx[dirNo];
        ny = y + dy[dirNo];
        int turnOff = 1;
        if(nx >= 0 and ny >= 0 and nx <= n-1 and ny <= m-1 and abs(grid[x][y] - grid[nx][ny]) == 2){
            turnOff = 1 + f(nx, ny, dirNo, turns, grid);
        }
        int turnOn = 1;
        nx = x + dx[(dirNo + 1) % 4];
        ny = y + dy[(dirNo + 1) % 4];
        if(turns == 0 and nx >= 0 and ny >= 0 and nx <= n-1 and ny <= m-1 and abs(grid[x][y] - grid[nx][ny]) == 2){
            turnOn = 1 + f(nx, ny, (dirNo + 1)%4, turns+1, grid);
        }
        return max(turnOff, turnOn);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi, 1);
                    int nx, ny;
                    for(int dirNo = 0;dirNo<4;dirNo++){
                        nx = i + dx[dirNo];
                        ny = j + dy[dirNo];
                        if(nx < 0 or ny < 0 or nx > n-1 or ny > m-1 or grid[nx][ny] == 1 or grid[nx][ny] == 0)
                            continue;
                        int val = 1 + f(nx, ny, dirNo, 0, grid);
                        maxi = max(maxi, val);
                    }
                }
            }
        }
        return maxi;
    }
};