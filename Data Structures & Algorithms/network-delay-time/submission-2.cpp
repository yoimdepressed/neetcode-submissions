class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0;i < times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        pq.push({0,k});
        int maxi = -1;
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;
            
            for(auto nei : adj[node])
            {
                int wt = nei.first;
                int curr = nei.second;
                if(dist[curr] > d + wt)
                {
                    dist[curr] = d + wt;
                    pq.push({dist[curr],curr});
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;




    }
};
