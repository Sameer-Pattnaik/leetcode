class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        bool elementDeleted = false;
        int maxOnes = 0;
        int nextLeftPosition = 0;
       while(left <= right && right < nums.size()) {
            if(nums[right] == 1) {
                right++;
            }
            else {
                if(!elementDeleted) {
                    right++;
                    nextLeftPosition = right;
                    elementDeleted = true;
                }
                else {
                    if(right - 1 - left > maxOnes){
                    maxOnes = right - 1 - left;
                    }
                    right++;
                    left = nextLeftPosition;
                    nextLeftPosition = right;

                }
            }
        }
        if(right - 1 - left > maxOnes) {  
            maxOnes = right - left - 1;
        }
        return maxOnes;
    }
};