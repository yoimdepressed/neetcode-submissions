class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& visited) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0' || visited[r][c] == 1)
        {
            return;
        }
        visited[r][c] = 1;
        dfs(r+1,c,grid,visited);
        dfs(r,c+1,grid,visited);
        dfs(r-1,c,grid,visited);
        dfs(r,c-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
