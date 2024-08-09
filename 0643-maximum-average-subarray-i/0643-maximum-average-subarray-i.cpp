class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int maxNo=INT_MIN;
      int sum=0;
      int i=0;
      int j=0;
      while(j<nums.size())
      {
        sum+=nums[j];
        if(j-i+1<k)
        {
           j++;
        }
        else if(j-i+1==k)
        {
            maxNo=max(maxNo,sum);
            sum-=nums[i];
            i++;
            j++;
        }
      }
      double ans=double(maxNo)/k;
      return ans;  
    }
};