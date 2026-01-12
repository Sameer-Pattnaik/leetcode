class Solution {
public:
    int solve(vector<int>&nums, int k){
        if(k<0){
            return 0;
        }
        int sum=0;
        int left=0;
        int count=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>k){
                sum-=nums[left];
                left++;
            }
           count+=(right-left+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result=solve(nums,goal)-solve(nums,goal-1);
        return result;
    }
};