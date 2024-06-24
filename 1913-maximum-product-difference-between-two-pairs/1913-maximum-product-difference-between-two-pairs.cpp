class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int prod1=1;
        int prod2=1;
       sort(nums.begin(),nums.end(),greater<int>());
       int k=2;
       for(int i=0;i<k;i++)
       {
        prod1*=nums[i];
       }
       sort(nums.begin(),nums.end());
       for(int i=0;i<k;i++)
       {
        prod2*=nums[i];
       }
       return (prod1-prod2);
    }
};