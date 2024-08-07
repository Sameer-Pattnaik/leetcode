class Solution {
public:
    int f(int index1,int index2,string &s,string &t,vector<vector<int>>&dp)
    {
        if(index2<0)
        {
            return 1;
        }
        if(index1<0)
        {
            return 0;
        }
        
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        if(s[index1]==t[index2])
        {
            return dp[index1][index2]=f(index1-1,index2-1,s,t,dp)+f(index1-1,index2,s,t,dp);
        }
        return dp[index1][index2]=f(index1-1,index2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};