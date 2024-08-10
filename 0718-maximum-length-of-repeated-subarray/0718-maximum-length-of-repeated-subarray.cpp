class Solution {
public:
int f(int index1,int index2,vector<int>&nums1,vector<int>&nums2,int &maxVal)
{

    if(index1<0 || index2<0)
    {
        return 0;
    }
    int val=0;
    if(nums1[index1]==nums2[index2])
    {
        val=1+f(index1-1,index2-1,nums1,nums2,maxVal);
        maxVal=max(maxVal,val);
    }
    f(index1-1,index2,nums1,nums2,maxVal);
    f(index1,index2-1,nums1,nums2,maxVal);
    return val;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int maxVal=0;
        f(n-1,m-1,nums1,nums2,maxVal);
        return maxVal;
    }
};