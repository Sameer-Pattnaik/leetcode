class Solution {
public:
void solve(vector<int>&nums,vector<int>&ans,int sol,int index)
{
    if(index>=nums.size())
    {
        ans.push_back(sol);
        return;
    }
    solve(nums,ans,sol^nums[index],index+1);
    solve(nums,ans,sol^0,index+1);
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;
    
        int sol=0;
        int index=0;
        solve(nums,ans,sol,index);
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
};