class Solution {
public:
void merge(vector<int>&nums,int s,int e,int mid)
{
    int n1=mid-s+1;
    int n2=e-mid;
    vector<int>first(n1);
    vector<int>second(n2);
    
    int k=s;
    for(int i=0;i<n1;i++)
    {
        first[i]=nums[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<n2;i++)
    {
        second[i]=nums[k];
        k++;
    }
    
    int i=0;
    int j=0;
    k=s;
    while(i<first.size() && j<second.size())
    {
        if(first[i]<second[j])
        {
            nums[k]=first[i];
            i++;
            k++;
        }
        else 
        {
            nums[k]=second[j];
            j++;
            k++;
        }
    }
    while(i<first.size())
    {
        nums[k]=first[i];
        i++;
        k++;
    }
    while(j<second.size())
    {
        nums[k]=second[j];
        j++;
        k++;
    }

}
void mergeSort(vector<int>&nums,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergeSort(nums,s,mid);
    mergeSort(nums,mid+1,e);
    merge(nums,s,e,mid);
}
    vector<int> sortArray(vector<int>& nums) {
       int s=0;
       int e=nums.size()-1;
       mergeSort(nums,s,e); 
       return nums;
    }
};