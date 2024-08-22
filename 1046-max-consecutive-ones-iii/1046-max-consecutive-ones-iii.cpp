class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int ZeroCnt=0;
       int j=0;
       int i=0;
       int maxNo=INT_MIN;
       while(j<nums.size())
       {
        if(nums[j]==0)
        {
            ZeroCnt++;
        }
        while(ZeroCnt>k)
        {
            if(nums[i]==0)
            {
                ZeroCnt--;
            }
            i++;
        }
        maxNo=max(maxNo,j-i+1);
        j++;
       }
       return maxNo; 
    }
};