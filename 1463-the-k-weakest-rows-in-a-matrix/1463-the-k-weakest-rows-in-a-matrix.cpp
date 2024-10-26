class Solution {
public:
    static bool compare(pair<int,int>a,pair<int,int>b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        map<int,int>mp;
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            mp[i]=count;
        }
        for(int i=0;i<mp.size();i++)
        {
            ans.push_back(make_pair(mp[i],i));
        }
        sort(ans.begin(),ans.end(),compare);
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].second);
        }
        return res;
    }
};