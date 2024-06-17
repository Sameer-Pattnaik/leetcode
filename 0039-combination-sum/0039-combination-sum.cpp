class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&output,vector<int>&candidates,int index,int target)
    {
        if(index>=candidates.size())
        {
            if(target==0)
            {
                ans.push_back(output);
                
            }
            return;
        }
        if(candidates[index]<=target)
        {
            output.push_back(candidates[index]);
            solve(ans,output,candidates,index,target-candidates[index]);
            output.pop_back();
        }
        solve(ans,output,candidates,index+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int>output;
      vector<vector<int>>ans;
      int index=0;
      solve(ans,output,candidates,index,target);
      return ans;  
    }
};