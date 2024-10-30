class Disjoint{
    public:
    vector<int>rank;
    vector<int>parent;
    vector<int>size;
    Disjoint(int n)
    {
    rank.resize(n+1,0);
    size.resize(n+1,1);
    parent.resize(n+1);
       for(int i=0;i<=n;i++)
       {
        parent[i]=i;
       }
    }
    int findUPar(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void findByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void findBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int countC=0;
        
            for(auto it:connections)
            {
                int u=it[0];
                int v=it[1];
                if(ds.findUPar(u)==ds.findUPar(v))
                {
                    countC++;
                }
                else
                {
                    ds.findBySize(u,v);
                }
            }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
               cnt++;
            }
        }
        int ans=cnt-1;
        if(countC>=ans)
        {
            return ans;
        }
        return -1;
    }
};