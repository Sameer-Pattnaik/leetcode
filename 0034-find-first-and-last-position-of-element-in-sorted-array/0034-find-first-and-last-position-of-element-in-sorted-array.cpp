class Solution {
public:
int firstOccurences(vector<int>&nums,int target)
{
    int n=nums.size();
    if(n==1 && target>0)
    {
        return 0;
    }
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=0;
    int pre=0;
    while(s<=e)
    {
        if(nums[mid]==target)
        {
            pre=(nums[mid]==target);
            ans=mid;
            e=mid-1;
            
            
        }
        else if(nums[mid]<target)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    if(ans || pre)
    {
    return ans;
    }
    else{
        return -1;
    }
}
int lastOccurences(vector<int>&nums,int target)
{
    int n=nums.size();
    int s=0;
    int e=n-1;
    int pre=0;
    if(n==1  && target>0)
    {
        return 0;
    }
    int mid=(s+e)/2;
    int ans=0;
    while(s<=e)
    {
        if(nums[mid]==target)
        {
            pre=(nums[mid]==target);
            ans=mid;
            s=mid+1;
            
            
        }
        else if(nums[mid]<target)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    if(ans || pre)
    {
    return ans;
    }
    else{
        return -1;
    }
}
    vector<int> searchRange(vector<int>& nums, int target) {
   int first=firstOccurences(nums,target);
    int last=lastOccurences(nums,target);
    return {first,last};
    }

};