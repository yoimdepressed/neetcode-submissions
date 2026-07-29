class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int node) {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int a,b;
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1;i < n+1;i++)
        {
            parent[i] = i;
        }
        for(int i = 0;i < n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int rootu = find(u);
            int rootv = find(v);
            if(rootu == rootv)
            {
                a = u;
                b = v;
            }
            if(size[rootu] > size[rootv])
            {
                parent[rootv] = parent[rootu];
                size[rootv] += size[rootu];
            }
            else
            {
                parent[rootu] = parent[rootv];
                size[rootu] += size[rootv];
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
