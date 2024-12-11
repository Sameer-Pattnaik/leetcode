class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=INT_MAX;
        int y=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=x)
            {
                x=nums[i];
            }
            else if(nums[i]<=y)
            {
                y=nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};