class Solution {
public:
    int solve(int index1,int index2,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(index1>index2)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        int ans=INT_MIN;
        for(int k=index1;k<=index2;k++)
        {
            int steps=nums[index1-1]*nums[k]*nums[index2+1]+solve(index1,k-1,nums,dp)+solve(k+1,index2,nums,dp);
            ans=max(ans,steps);
        }
        return dp[index1][index2]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp);
    }
};