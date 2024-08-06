class Solution {
public:
    bool isPrime(int n)
    {
        if(n<2)
        {
            return false;
        }
        for(int i=2;i*i<=n;i++)
        {
             if(n%i==0)
             {
                return false;
             }
        }
    
            return true;
        
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        
        int m=nums[0].size();
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            ans.push_back(nums[i][j]);
            i++;
            j++;
        }
        int r=0;
        int c=n-1;
        while(r<n && c>=0)
        {
            ans.push_back(nums[r][c]);
            r++;
            c--;
        }
        vector<int>result;
        for(int i=0;i<ans.size();i++)
        {
            if(isPrime(ans[i]))
            {
                result.push_back(ans[i]);
            }
        }
        int maxNo=0;
        for(int i=0;i<result.size();i++)
        {
            maxNo=max(maxNo,result[i]);
        }
        
        
        return maxNo;

    

    }
};