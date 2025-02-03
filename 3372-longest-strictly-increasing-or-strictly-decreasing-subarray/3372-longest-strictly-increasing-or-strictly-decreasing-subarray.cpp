class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int great=1;
        int less=1;
        int ans=1;
        if(nums.size()==1)
        {
            return 1;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                great++;
                less=1;
            }
            else if(nums[i]<nums[i-1])
            {
                less++;
                great=1;
            }
            else{
                less=1;
                great=1;
            }
            ans=max({ans,less,great});
        }
       return ans;
    }
};