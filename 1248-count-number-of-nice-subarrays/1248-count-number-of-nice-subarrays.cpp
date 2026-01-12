class Solution {
public:
    int solve(vector<int>&nums,int k){
        
        int left=0;
        int count=0;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2!=0){
                k--;
            }
            while(k<0){
                if(nums[left]%2!=0){
                k++;
                }
                left++;
            }
             count+=(right-left+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result=solve(nums,k)-solve(nums,k-1);
        return result;
    }
};