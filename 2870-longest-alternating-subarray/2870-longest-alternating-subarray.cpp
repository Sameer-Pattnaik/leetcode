class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
        bool f=0;
        int maxi=1;
        int count=1;
        
        for(int j=i;j<nums.size()-1;j++)
        {
            if(!f && nums[j+1]-nums[j]==1)
            {
                count++;
                maxi=max(maxi,count);
            }
            else if(f && nums[j+1]-nums[j]==-1)
            {
                count++;
                maxi=max(maxi,count);
            }
            else{
                break;
            }
            f=!f;
            
        }
        ans=max(ans,maxi);
        }
        if(ans==1)
        {
            return -1;
        }
        return ans;
    }
};