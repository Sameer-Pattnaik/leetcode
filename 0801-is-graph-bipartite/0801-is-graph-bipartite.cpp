class Solution {
public:
    bool bfs(int node,vector<vector<int>>&graph,vector<int>&color)
    {
        queue<int>q;
        color[node]=0;
        q.push(node);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto adjNode:graph[node])
            {
                if(color[adjNode]==-1)
                {
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                }
                if(color[adjNode]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
             if(!bfs(i,graph,color))
              {
                return false;
              }
            }
        }
        return true;
        
    }
};