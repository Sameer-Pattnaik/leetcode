class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                mp[nums[i]]++;
            }
        }
        int result=1;
        int sol=0;
        for(auto it:mp)
        {
            if(result!=it.first)
            {
                return result;
            }
            result++;
        }
        return result;
    }
};