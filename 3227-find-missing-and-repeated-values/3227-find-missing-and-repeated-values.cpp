class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        vector<int>result;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans.push_back(grid[i][j]);
            }
        }
        map<int,int>mp;
        for(int i=0;i<ans.size();i++)
        {
            mp[ans[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            {
                result.push_back(it.first);
            }
        }
        vector<int>sol;
        for(auto it:mp)
        {
           sol.push_back(it.first);
        }
        vector<int>output;
        for(int i=0;i<ans.size();i++)
        {
            output.push_back(i+1);   
        }
        int i=0;
        int j=0;
        int missing=0;
        while(i<sol.size() && j<output.size())
        {
             if(sol[i]==output[j])
             {
                i++;
                j++;
             }
             else
             {
                missing=output[j];
                result.push_back(missing);
                break;
             }
             
        }
        while(j<output.size() && result.size()==1)
        {
            missing=output[j];
            result.push_back(missing);
        }
        return result;
    }
};