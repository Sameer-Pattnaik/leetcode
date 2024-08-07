class Disjoint{
    vector<int>rank,parent;
    public:
    Disjoint(int n)
    {
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    }
    int findByUPar(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findByUPar(parent[node]);
    }  
    void unionByRank(int u,int v)
    {
        int ulp_u=findByUPar(u);
        int ulp_v=findByUPar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }


    } 
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                  string mail=accounts[i][j];
                  if(mp.find(mail)==mp.end())
                  {
                    mp[mail]=i;
                  }
                  else
                  {
                    ds.unionByRank(i,mp[mail]);
                  }
            }
        }
        vector<string>ans[n];
        for(auto it:mp)
        {
            int node=ds.findByUPar(it.second);
            string mail=it.first;
            ans[node].push_back(mail);
        }
        vector<vector<string>>result;
        for(int i=0;i<n;i++)
        {
            if(ans[i].size()==0)
            {
                continue;
            }
            
                sort(ans[i].begin(),ans[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(auto it:ans[i])
                {
                    temp.push_back(it);
                }
                result.push_back(temp);
                
            
        }
        sort(result.begin(),result.end());
        return result;
    }
};