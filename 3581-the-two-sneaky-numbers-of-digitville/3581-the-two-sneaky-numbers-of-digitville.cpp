class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:mp)
        {
            if(it.second==2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};