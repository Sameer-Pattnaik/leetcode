class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(mat[i][j]==1)
               {
                  mp[i]++;
               }
            }
    
        }
        int maxNo=0;
        int target=0;
        for(auto it:mp)
        {
            if(it.second>maxNo)
            {
               maxNo=max(maxNo,it.second);
               target=it.first;
            }
        }
        
        ans.push_back(target);
        ans.push_back(maxNo);
        return ans;
    }
};