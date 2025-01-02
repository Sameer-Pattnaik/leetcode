class Solution {
public:
    void help(vector<vector<char>>&board,unordered_map<string,int>&mp,string &t,int i,int j,unordered_map<string,int>&store,int len){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j]=='0'){return;}
        if(store[t]==0){return;}
        if(t.size()>=len){return;}
        char temp1=board[i][j];
        t.push_back(board[i][j]);
        board[i][j]='0';
        mp[t]=1;
        help(board,mp,t,i+1,j,store,len);
        help(board,mp,t,i,j+1,store,len);
        help(board,mp,t,i-1,j,store,len);
        help(board,mp,t,i,j-1,store,len);
        board[i][j]=temp1;
        t.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<string,int>mp;
        unordered_map<string,int>store;
        int len=0;
        string g;
        for(int i=0;i<words.size();i++){
            g="";
            for(int j=0;j<words[i].size();j++){
                 g+=words[i][j];
                 store[g]=1;
            }
            len=max(len,(int)words[i].size());
        }
        string t="";
        store[t]=1;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                help(board,mp,t,i,j,store,len);
            }
        }
        vector<string>ans;
        for(auto x:words){
            if(mp[x]){
                ans.push_back(x);
            }
        }
        return ans;
    }
};