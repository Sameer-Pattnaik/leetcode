class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&output,set<vector<int>>&st)
    {
        if(index>=nums.size())
        {
            st.insert(nums);
            return; 
        }
    
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(index+1,nums,output,st);
            swap(nums[index],nums[i]);
        
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>output;
        set<vector<int>>st;
        solve(0,nums,output,st);
        vector<vector<int>>ans={st.begin(),st.end()};
        return ans;
    }
};