class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);

        stack<int> st;
        st.push(0);
        visited[0] = 1;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (int v : rooms[u])
            {   
                if (!visited[v]) 
                {
                    visited[v] = 1;
                    st.push(v);
                }
            }
        }

        for (bool v : visited)
        {
            if (v == 0)
                return 0;
        }
        return 1;
    }
};