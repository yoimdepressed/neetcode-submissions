class Solution {
public:
    bool checkcycle(vector<vector<int>>& adj, vector<int>& visited) {
        queue<pair<int,int>> q;
        q.push({0,-1});
        visited[0] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto nei : adj[node])
            {
                if(!visited[nei])
                {
                    visited[nei] = 1;
                    q.push({nei,node});
                }
                else if(nei != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(int v,vector<vector<int>>& adj, vector<int>& visited) {
        visited[v] = 1;
        for(auto nei : adj[v])
        {
            if(!visited[nei]) dfs(nei,adj,visited);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
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
            if(comp > 1) return false;
        }
        vector<int> visit(n,0);
        if(checkcycle(adj,visit)) return false;

        return true;
        
    }
};
