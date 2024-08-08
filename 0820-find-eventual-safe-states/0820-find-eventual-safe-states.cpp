class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&visited,vector<int>&pathVisited,vector<int>&check)
    {
        visited[node]=1;
        pathVisited[node]=1;
        check[node]=0;
        for(auto it:graph[node])
        {
            if(!visited[it])
            {
                if(dfs(it,graph,visited,pathVisited,check))
                {
                
                    return true;
                }
            }
            if(pathVisited[it])
            {
                
                return true;
            }
        }
        pathVisited[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>visited(n,0);
       vector<int>pathVisited(n,0);
       vector<int>check(n);
       for(int i=0;i<n;i++)
       {
        if(!visited[i])
        {
            dfs(i,graph,visited,pathVisited,check);
        }
       }
       vector<int>sol;
       for(int i=0;i<n;i++)
       {
        if(check[i]==1)
        {
            sol.push_back(i);
        }
       }
       return sol; 
    }
};