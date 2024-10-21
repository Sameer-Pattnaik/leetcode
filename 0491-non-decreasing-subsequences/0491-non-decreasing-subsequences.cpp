class Solution {
public:
    void solve(int index,vector<vector<int>>&result,vector<int>ans,vector<int>&nums)
    {
        if(index>=nums.size())
        {
            if(ans.size()>1)
            {
            result.push_back(ans);
            }
            return;
        }
        solve(index+1,result,ans,nums);
        ans.push_back(nums[index]);
        solve(index+1,result,ans,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        int index=0;
        solve(index,result,ans,nums);
        set<vector<int>>output;
        for(int i=0;i<result.size();i++)
        {
            bool flag=false;
            for(int j=1;j<result[i].size();j++)
            {
            
                if(result[i][j]<result[i][j-1])
                {
                    flag=true;
                    break;
                }
        
            }
            if(flag==false)
            {
                output.insert(result[i]);
            }
        }
        vector<vector<int>>sol;
        for(auto it:output)
        {
            sol.push_back(it);
        }
        return sol;
    }
};