class Solution {
public:
    int f(int index1,int index2,string &word1,string &word2,vector<vector<int>>&dp)
    {
        if(index1<0)
        {
            return index2+1;
        }
        if(index2<0)
        {
            return index1+1;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        if(word1[index1]==word2[index2])
        {
            return f(index1-1,index2-1,word1,word2,dp);
        }
        return dp[index1][index2]= 1+min(f(index1-1,index2,word1,word2,dp),min(f(index1,index2-1,word1,word2,dp),f(index1-1,index2-1,word1,word2,dp)));
    } 
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};