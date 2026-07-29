class Solution {
public:
    void dfs(int v,vector<vector<int>>& adj, vector<int>& visited) {
        visited[v] = 1;
        for(auto nei : adj[v])
        {
            if(!visited[nei]) dfs(nei,adj,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0;i < edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        int comp = 0;
        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                comp++;
            }
        }
        return comp;
    }
};
