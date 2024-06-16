class Solution {
public:
    int jump(vector<int>& nums) {
      int maxReach=nums[0];
      int steps=nums[0];
      int jump=1;
      
      
      if(nums.size()<=1 )
      {
        return 0;
      }
      for(int i=1;i<nums.size();i++)
      {
        steps--;
        if(i==nums.size()-1)
        {
             return jump;
        }
        maxReach=max(maxReach,nums[i]+i);
    
        if(steps==0)
        {
            jump++;
            if(maxReach<i)
            {
                return -1;
            }
            steps=maxReach-i;
        }
      } 
      return -1; 
    
    }
};