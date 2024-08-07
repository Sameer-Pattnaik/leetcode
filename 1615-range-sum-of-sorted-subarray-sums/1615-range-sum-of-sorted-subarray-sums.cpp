class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            ans.push_back(sum);
        }
       }
       sort(ans.begin(),ans.end());
       vector<int>result;
       for(int i=left-1;i<right;i++)
       {
        result.push_back(ans[i]);
       }
       long long sol=0;
       for(int i=0;i<result.size();i++)
       {
        sol+=result[i];
       }
   return sol%1000000007;
    }
};