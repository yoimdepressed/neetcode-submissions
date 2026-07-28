class Solution {
public:
    int time = 0;
    void bfs(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i < n;i++)
            {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                //top
                if(row-1 >= 0 && grid[row - 1][column] == 1)
                {
                    grid[row - 1][column] = 2;
                    q.push({row-1,column});
                }
                // bottom
                if(row + 1 < grid.size() && grid[row + 1][column] == 1)
                {
                    grid[row + 1][column] = 2;
                    q.push({row + 1, column});
                }
                // left
                if(column - 1 >= 0 && grid[row][column - 1] == 1)
                {
                    grid[row][column - 1] = 2;
                    q.push({row, column - 1});
                }
                // right
                if(column + 1 < grid[0].size() && grid[row][column + 1] == 1)
                {
                    grid[row][column + 1] = 2;
                    q.push({row, column + 1});
                }
            }
            if(!q.empty())time++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        bfs(grid);
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == 1) return -1; 
            }
        }
        return time;
    }
};