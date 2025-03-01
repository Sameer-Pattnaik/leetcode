class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<nums.size()-1 && nums[i]==nums[i+1])
            {
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
            if (nums[i]!=0) swap(nums[j++],nums[i]);
        }
        
        return nums;
    }
};