class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());               
        int i = 0;
        int n = nums.size();
        int groups = 0;
        while (i < n) {                               
            int limit = nums[i] + k;                
            i = upper_bound(nums.begin() + i,nums.end(),limit) - nums.begin();
            ++groups;                                 
        }
        return groups;                                
    }
};