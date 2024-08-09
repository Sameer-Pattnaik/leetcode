class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push(make_pair(0,make_pair(src,0)));
        while(!pq.empty())
        {
            int key=pq.top().first;
            int node=pq.top().second.first;
            int dis=pq.top().second.second;
            pq.pop();
            if(key>k)
            {
                continue;
            }
            for(auto it:adj[node])
            {
                int edgeWeight=it.second;
                int adjNode=it.first;
                if(dis + edgeWeight<dist[adjNode])
                {
                    dist[adjNode]=dis + edgeWeight;
                    pq.push(make_pair(key+1,make_pair(adjNode,dist[adjNode])));

                }
            }
        }
        if(dist[dst]==1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};