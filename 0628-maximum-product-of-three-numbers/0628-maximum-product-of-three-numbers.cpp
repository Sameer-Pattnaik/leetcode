class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int ans=max(nums[0]*nums[1]*nums[j],nums[j]*nums[j-1]*nums[j-2]);
        return ans;
    }
};