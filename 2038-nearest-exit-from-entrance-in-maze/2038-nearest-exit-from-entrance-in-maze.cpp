class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int r = maze.size();
        int c = maze[0].size();
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        maze[entrance[0]][entrance[1]] = '+';
        int moves = 0;
while(!q.empty()){
    int l=q.size();
    moves++;
    for(int i=0;i<l;i++){
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int x=u+dx[k];
            int y=v+dy[k];
            if(x>=0 and y>=0 and x<r and y<c and maze[x][y]=='.'){
                if(x==0 or y==0 or x==r-1 or y==c-1) return moves;
                maze[x][y]='+';
                q.push({x,y});
            }
        }
    }
}
        return -1;
    }
};