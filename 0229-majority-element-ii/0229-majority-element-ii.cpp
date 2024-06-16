class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int k=n/3;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>k)
            {
                 ans.push_back(it.first);
            }
        }
        return ans;
    }
};