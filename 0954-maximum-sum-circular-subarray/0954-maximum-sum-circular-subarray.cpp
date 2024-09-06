class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;
        int currSum=0;
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(currSum<0)
            {
                currSum=0;
            }
            maxSum=max(maxSum,currSum);
        }
        currSum=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(currSum>0)
            {
                currSum=0;
            }
            minSum=min(minSum,currSum);
        }
        int check=0;
        for(int i=0;i<nums.size();i++)
        {
            
            totalSum+=nums[i];
            if(nums[i]<0)
            {
                check++;
            }
        }
        if(check==nums.size())
        {
            sort(nums.begin(),nums.end());
            int ans=nums[nums.size()-1];
            return ans;
        }
        int sol=totalSum-minSum;
        return max(sol,maxSum);
    }
};