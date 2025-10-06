class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<tuple<int,int,int>> edges;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    edges.push_back({max(grid[i][j], grid[i-1][j]), i*n+j, (i-1)*n+j});
                if (j > 0)
                    edges.push_back({max(grid[i][j], grid[i][j-1]), i*n+j, i*n+j-1});
            }
        }
        
        sort(edges.begin(), edges.end());
        vector<int> parent(m * n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int x, int y) {
            parent[find(x)] = find(y);
        };
        
        for (auto [cost, u, v] : edges) {
            unite(u, v);
            if (find(0) == find(m*n-1))
                return cost;
        }
        return grid[0][0];
    }
};