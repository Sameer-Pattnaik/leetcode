class Solution {
public:
    bool binarySearch(int start,int end,vector<int>&arr,int key)
    {
        int mid=(start+end)/2;
        while(start<=end)
        {
            if(arr[mid]==key)
            {
                return true;
            }
            else if(arr[mid]>key)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=(start+end)/2;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       
       for(int i=0;i<n;i++)
       {
        if(matrix[i][0]<=target && target<=matrix[i][m-1])
        {
            return binarySearch(0,m-1,matrix[i],target);
        }
       }
       return false; 
    }
};