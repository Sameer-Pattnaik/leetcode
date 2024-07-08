class Solution {
public:
bool isSorted(int nums[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]>nums[j])
            {
                return false;
            }
        }
    }
    return true;
}
    int minimumRightShifts(vector<int>& nums) {
    int n=nums.size();
    int *temp=new int[n];
    int count=0;
    for(int i=0;i<n;i++)
    {
        temp[i]=nums[i];
    }
    if(!isSorted(temp,n))
    {
    int j=1;
    while(!isSorted(temp,n))
    {
    for(int i=0;i<n;i++)
    {
        temp[i]=nums[((n-j)+i)%n];
    }
    count++;
    j++;
    if((count==n) && (!isSorted(temp,n)))
    {
    return -1;
    }
    }
    }
    
    return count;
    
    
    
    }
};