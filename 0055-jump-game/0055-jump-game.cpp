class Solution {
public:
    bool canJump(vector<int>& nums) {
        int aim=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]+i>=aim)
            {
                aim=i;
            }
        }
        return aim==0;
    }
};