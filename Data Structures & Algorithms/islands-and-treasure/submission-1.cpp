class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0;i < s;i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r-1 >= 0 && grid[r-1][c] == INF)
                {
                    grid[r-1][c] = min(grid[r-1][c], grid[r][c] + 1);
                    q.push({r-1,c});
                }
                if(c-1 >= 0 && grid[r][c-1] == INF)
                {
                    grid[r][c-1] = min(grid[r][c-1], grid[r][c] + 1);
                    q.push({r,c-1});
                }
                if(r+1 < m && grid[r+1][c] == INF)
                {
                    grid[r+1][c] = min(grid[r+1][c], grid[r][c] + 1);
                    q.push({r+1,c});
                }
                if(c+1 < n && grid[r][c+1] == INF)
                {
                    grid[r][c+1] = min(grid[r][c+1], grid[r][c] + 1);
                    q.push({r,c+1});
                }
            }
        }
    }
};
