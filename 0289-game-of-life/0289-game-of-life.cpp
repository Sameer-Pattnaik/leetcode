class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // live cell = 1   // dead cell = 0
        // if 1: <two 1 or >three 1 -> 0
        // if 0: three 1 -> 1
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> count_live(m, vector<int>(n,0));
        // count 1 for all directions
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){ // update 8 directions 
                    if(i>0) count_live[i-1][j]++; // left
                    if(i<m-1) count_live[i+1][j]++; // right
                    if(j>0) count_live[i][j-1]++; // up
                    if(j<n-1) count_live[i][j+1]++; // down
                    if(i>0 && j>0) count_live[i-1][j-1]++; // north-west
                    if(i>0 && j<n-1) count_live[i-1][j+1]++; // north-east
                    if(i<m-1 && j>0) count_live[i+1][j-1]++; // south-west
                    if(i<m-1 && j<n-1) count_live[i+1][j+1]++; // south-east
                }
            }
        }
        // update state as per rules given in problem
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){  // currently live state [1]
                    if(count_live[i][j] < 2 || count_live[i][j] > 3) board[i][j] =0;
                } else{ // currently dead state [0]
                    if(count_live[i][j] == 3) board[i][j] = 1;
                }
            }
        }
        // If you like this solution, you can upvote ⬆ it to make it
        // more accessible and easier to understand for others
    }
};