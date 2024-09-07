class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        for(auto it:nums)
        {
            if(idx==0 || idx==1 || nums[idx-2]!=it)
            {
                nums[idx]=it;
                idx++;
            }
        }
        return idx;
    }
};