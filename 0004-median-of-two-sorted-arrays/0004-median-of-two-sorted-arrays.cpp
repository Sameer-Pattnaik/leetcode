class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    vector<int>arr3;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(nums1[i]<nums2[j])
        {
            arr3.push_back(nums1[i]);
            i++;
        }
        else
        {
            arr3.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n)
    {
        arr3.push_back(nums1[i]);
        i++;
    }
    while(j<m)
    {
        arr3.push_back(nums2[j]);
        j++;
    }
    for(int i=0;i<n+m;i++)
    {
        cout<<arr3[i]<<" ";
    }
    int start=0;
    int end=(n+m)-1;
    double median=0;
    if((n+m)%2!=0)
    {
        median=(start+end)/2;
        return arr3[median];
    }
    else
    {
        median=(start+end)/2.0;
        
        return (static_cast<float>(arr3[median+1])+static_cast<float>(arr3[median]))/2.0;
    }
    
}

    
};