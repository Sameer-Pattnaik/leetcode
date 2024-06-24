class Solution {
public:
    int f(vector<int>&dp,int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0 || n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=f(dp,n-1)+f(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return f(dp,n);
    }
};