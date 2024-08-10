class Solution {
public:
int f(int index1,int index2,vector<int>&nums1,vector<int>&nums2,int &maxVal,vector<vector<int>>&dp)
{

    if(index1<0 || index2<0)
    {
        return 0;
    }
    if(dp[index1][index2]!=-1)
    {
        return dp[index1][index2];
    }
    int val=0;
    if(nums1[index1]==nums2[index2])
    {
        val=1+f(index1-1,index2-1,nums1,nums2,maxVal,dp);
        maxVal=max(maxVal,val);
    }
    f(index1-1,index2,nums1,nums2,maxVal,dp);
    f(index1,index2-1,nums1,nums2,maxVal,dp);
    return dp[index1][index2]=val;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxVal=0;
        f(n-1,m-1,nums1,nums2,maxVal,dp);
        return maxVal;
    }
};