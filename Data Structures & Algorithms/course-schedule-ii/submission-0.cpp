class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> list(numCourses,0);
        for(int i = 0;i < prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            list[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0;i < list.size();i++)
        {
            if(list[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i < n;i++)
            {
                int idx = q.front();
                q.pop();
                ans.push_back(idx);
                for(int j = 0;j < adj[idx].size();j++)
                {
                    list[adj[idx][j]]--;
                    if(list[adj[idx][j]] == 0)
                    {
                        q.push(adj[idx][j]);
                    }
                }
            }
        }
        for(int i = 0;i < list.size();i++)
        {
            if(list[i] != 0) return {};
        }
        return ans;
    }
};
