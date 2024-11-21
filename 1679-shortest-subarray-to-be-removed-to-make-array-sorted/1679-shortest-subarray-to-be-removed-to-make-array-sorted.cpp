class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int first=-1;
        int last=-1;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
          if(arr[i]>arr[i+1])
          {
            if(first==-1)
            {
                first=i;
            }
            last=i;
          }
        }
        if(first==-1)
        {
            return 0;
        }
        int ans=min(last+1,n-first-1);
        for(int i=0;i<=first;i++)
        {
            for(int j=last+1;j<n;j++)
            {
                if(arr[i]<=arr[j])
                {
                    ans=min(ans,j-i-1);
                    break;
                }
            }
        }
        return ans;
    }
};