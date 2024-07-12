class Solution {
public:
int solve(vector<int>&nums,int index,vector<int>&dp)
{
    
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int incl=solve(nums,index+2,dp)+nums[index];
    int excl=solve(nums,index+1,dp)+0;
    return dp[index]=max(incl,excl);
}
    int robbery(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int index=0;
        return solve(nums,index,dp);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>ans1;
        vector<int>ans2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
               ans1.push_back(nums[i]);
            }
            if(i!=nums.size()-1)
            {
                ans2.push_back(nums[i]);
            }
        }
        int firstPath=robbery(ans1);
        int secondPath=robbery(ans2);
        return max(firstPath,secondPath);
    }
};