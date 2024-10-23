class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(i>j || i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            dp[i][j]=solve(i+1,j-1,s,dp);
        }
        else{
            dp[i][j]=0;
        }
        solve(i+1,j,s,dp);
        solve(i,j-1,s,dp);
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        int n=s.length();
      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      solve(0,n-1,s,dp);
      int x=0;
      int y=0;
      for(int i=0;i<=n;i++)
      {
        for(int j=i+1;j<=n;j++)
        {
           if(dp[i][j]==1 && j-i>y-x)
           {
             x=i;
             y=j;
           } 
        }
      }
      return s.substr(x,y-x+1);
    }
};