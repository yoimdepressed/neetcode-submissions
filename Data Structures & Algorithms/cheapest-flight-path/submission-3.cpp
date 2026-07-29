class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i < flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][2],flights[i][1]});
        }
        queue<vector<int>> pq;
        //stops,distance,node
        pq.push({0,0,src});
        vector<int> distance(n,1e9);
        distance[src] = 0;
        while(!pq.empty())
        {
            auto it = pq.front();
            int stops = it[0];
            int cost = it[1];
            int node = it[2];
            pq.pop();
            if(stops > k) continue;
            for(auto nei : adj[node])
            {
                int wt = nei.first;
                int nextnode = nei.second;
                if(distance[nextnode] > cost + wt)
                {
                    distance[nextnode] = cost + wt;
                    pq.push({stops+1,distance[nextnode],nextnode});
                }
            }
        }
        if(distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};
