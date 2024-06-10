class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNo=INT_MAX;
        int n=nums.size();
       for(int i=0;i<n;i++)
       {
           minNo=min(minNo,nums[i]);
       } 
       return minNo;
    }
};