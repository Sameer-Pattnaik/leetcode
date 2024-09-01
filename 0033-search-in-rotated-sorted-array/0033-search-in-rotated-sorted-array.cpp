class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int low=0;
       int high=n-1;
       int mid=(high+low)/2;
       while(low<=high)
       {
        if(nums[mid]==target)
        {
            return mid;
        }
         if(nums[low]<=nums[mid])
           {
                if(nums[low]<=target && target<=nums[mid])
                {
                     high=mid-1; 
                }
                else
                {
                      low=mid+1;
                }
           }
           else
           {
               if(nums[mid]<=target && target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                     high=mid-1;
                }
           }
           mid=(high+low)/2;
       }
       return -1; 
    }
};