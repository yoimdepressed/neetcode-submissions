class Solution {
public:
    vector<string> ans;
    unordered_map< string, priority_queue<string,vector<string>,greater<string>> > adj;
    void dfs(string airport) {
        while(!adj[airport].empty())
        {
            string next = adj[airport].top();
            adj[airport].pop();
            dfs(next);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0;i < tickets.size();i++)
        {
            adj[tickets[i][0]].push(tickets[i][1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
