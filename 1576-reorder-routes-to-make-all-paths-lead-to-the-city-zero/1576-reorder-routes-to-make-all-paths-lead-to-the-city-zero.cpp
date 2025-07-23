class Solution {
public:
    int ans = 0;  
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis) {
        vis[node] = 1;  
        for (int i = 0; i < adj[node].size(); i++) {
            int nei = adj[node][i].first;   
            int sign = adj[node][i].second;  
            if (vis[nei] == 0) {  
                ans = ans + sign;  
                dfs(nei, adj, vis);  
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) { 
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});  
            adj[v].push_back({u, 0});  
        }
        vector<int> vis(n, 0); 
        dfs(0, adj, vis);       
        return ans; 
    }
};