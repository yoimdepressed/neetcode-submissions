class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(int i = 0;i < points.size();i++)
        {
            int x1 = points[i][0];
            int x2 = points[i][1];
            int dist = (x1 * x1) + (x2 * x2);
            pq.push({dist,x1,x2});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        for(int i = 0;i < k;i++)
        {
            auto it = pq.top();
            ans.push_back({it[1],it[2]});
            pq.pop();
        }
        return ans;
    }
};
