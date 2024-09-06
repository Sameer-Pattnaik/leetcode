class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       {
        if(mp.count(nums[i]))
        {
            if(abs(mp[nums[i]]-i)<=k)
            {
                return true;
            }
        }
        mp[nums[i]]=i;
       } 
       return false;
    }
};