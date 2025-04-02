class Solution {
public:
double dfs(vector<string>queries,map<string,vector<pair<string,double>>>&adj)
{
    string src=queries[0];
    string dst=queries[1];
    map<string,int>vis;
    vis[src]=1;
    double ans=-1.0;
    queue<pair<string,double>>q;
    q.push({src,1});
    while(!q.empty())
    {
        string n=q.front().first;
        double cost=q.front().second;
        q.pop();
        if(n==dst)
        {
            return cost;
        }
        for(auto it:adj[n])
        {
            string temp=it.first;
            double c=it.second;
            if(!vis[temp])
            {
                vis[temp]=1;
                q.push({temp,c*cost});
            }
        }
    }
    return -1;

}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         
         int cnt=0;
          map<string,vector<pair<string,double>>>adj;
         for(int i=0;i<equations.size();i++)
         {
            string src=equations[i][0];
            string dst=equations[i][1];
            adj[src].push_back({dst,values[i]});
            adj[dst].push_back({src,1/values[i]});
         }
         vector<double>ans;

         for(auto query:queries)
         {
            if(adj.find(query[0])==adj.end() || adj.find(query[1])==adj.end())
            {
                ans.push_back(-1);
                continue;
            }
            double st= dfs(query,adj);
            ans.push_back(st);
         }
         return ans;

    }
};