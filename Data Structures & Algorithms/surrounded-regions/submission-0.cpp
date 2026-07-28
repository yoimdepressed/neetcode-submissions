class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m <= 1 || n <= 1) return; // Tiny optimization: a 1D board can't have surrounded regions
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O') 
            {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if(board[i][n-1] == 'O') 
            {
                q.push({i, n-1});
                visited[i][n-1] = 1;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O' && visited[0][i] == 0) 
            {
                q.push({0, i});
                visited[0][i] = 1;
            }
            if(board[m-1][i] == 'O' && visited[m-1][i] == 0) 
            {
                q.push({m-1, i});
                visited[m-1][i] = 1;
            }
        }
        
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                // top
                if(row - 1 >= 0 && board[row - 1][col] == 'O' && visited[row - 1][col] == 0) {
                    visited[row - 1][col] = 1;
                    q.push({row - 1, col});
                }
                // bottom
                if(row + 1 < m && board[row + 1][col] == 'O' && visited[row + 1][col] == 0) {
                    visited[row + 1][col] = 1;
                    q.push({row + 1, col});
                }
                // left
                if(col - 1 >= 0 && board[row][col - 1] == 'O' && visited[row][col - 1] == 0) {
                    visited[row][col - 1] = 1;
                    q.push({row, col - 1});
                }
                // right
                if(col + 1 < n && board[row][col + 1] == 'O' && visited[row][col + 1] == 0) {
                    visited[row][col + 1] = 1;
                    q.push({row, col + 1});
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};