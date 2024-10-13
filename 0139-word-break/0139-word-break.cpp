class Solution {
public:
    bool f(string s,unordered_set<string>&set,vector<int>&dp,int start)
    {
        int n=s.length();
        if(start==s.size())
        {
            return true;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
       
       for(int i=start;i<n;i++)
       {
          if(set.count(s.substr(start,i+1-start)) && f(s,set,dp,i+1))
          {
                return dp[start]=true;
          }
       }
       return dp[start]=false; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        unordered_set<string>set(wordDict.begin(),wordDict.end());
        return f(s,set,dp,0);
    }
};