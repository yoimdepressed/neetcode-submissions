
class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i < n;i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool union_by_size(int u,int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if(rootu == rootv)
        {
            return false;
        }
        if(size[rootu] < size[rootv])
        {
            parent[rootu] = parent[rootv];
            size[rootv] += size[rootu];
        }
        else
        {
            parent[rootv] = parent[rootu];
            size[rootu] += size[rootv];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> dist;
        int n = points.size();
        for(int i = 0;i < points.size();i++)
        {
            for(int j = i+1;j < points.size();j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                dist.push_back({d,i,j});
            }
        }
        sort(dist.begin(),dist.end());
        DSU dsu(n);
        int cost = 0;
        int edges = 0;
        for(auto it : dist)
        {
            int c = it[0];
            int u = it[1];
            int v = it[2];
            if(dsu.union_by_size(u,v))
            {
                cost += c;
                edges++;
            }
            if(edges == n-1) break;
        }
        return cost;

    }
};
