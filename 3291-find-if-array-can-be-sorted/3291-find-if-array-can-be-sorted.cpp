class Solution {
public:
    
    bool canSortArray(vector<int>& nums) {
      map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
        int count=0;
        int n=nums[i];
        while(n>0)
        {
            count++;
            n=n&(n-1);
        }
        mp[nums[i]]=count;
      }
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]>nums[j])
            {
                if(mp[nums[i]]!=mp[nums[j]])
                {
                    return false;
                }
            }
        }
      }
      return true;
      
    }
};