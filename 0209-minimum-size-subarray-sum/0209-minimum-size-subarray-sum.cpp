class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int minNo=1e9;
       int i=0;
       int j=0;
       int sum=0;
       while(j<nums.size())
       {
          sum+=nums[j];
          if(sum<target)
          {
            j++;
          }
          
          else
          {
            while(sum>=target)
            {
                sum-=nums[i];
                minNo=min(minNo,j-i+1);
                i++;
            }
            
            j++;
          }
       }
       if(minNo==1e9)
       {
        return 0;
       }
       return minNo; 
    }
};