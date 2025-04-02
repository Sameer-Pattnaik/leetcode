class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxNo=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    
                    maxNo=max(maxNo,(long long)(nums[i]-nums[j])*nums[k]);
                    
                }
            }
        }
        if(maxNo<0)
        {
            return 0;
        }
        return maxNo;
    }
};