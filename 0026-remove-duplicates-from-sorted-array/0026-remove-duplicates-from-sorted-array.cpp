class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int index=0;
       for(int i=0;i<nums.size();i++)
       {
          if(i==0)
          {
            nums[index]=nums[i];
            index++;
        
          }
          else if(i>0 && nums[i]==nums[i-1])
          {
            continue;
          }
          else
          {
            nums[index]=nums[i];
            index++;
          }
       }
       return index; 
    }
};