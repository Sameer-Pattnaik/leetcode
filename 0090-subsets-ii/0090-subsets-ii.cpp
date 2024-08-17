class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>ans,set<vector<int>>&st)
    {
        if(index>=nums.size())
        {
            sort(ans.begin(),ans.end());
            st.insert(ans);
            
            return;
        }
        solve(index+1,nums,ans,st);
        ans.push_back(nums[index]);
        solve(index+1,nums,ans,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        set<vector<int>>st;
        int index=0;
        solve(index,nums,ans,st);
        vector<vector<int>>result={st.begin(),st.end()};
        return result;
    }
};