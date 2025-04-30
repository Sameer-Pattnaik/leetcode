class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int countEven=0;
        for(int i=0;i<nums.size();i++)
        {
            int count1=0;
            while(nums[i])
            {
                int rem=nums[i]%10;
                count1++;
                nums[i]=nums[i]/10;
            }
            if(count1%2==0)
            {
                countEven++;
            }
        }
        return countEven;
    }
};