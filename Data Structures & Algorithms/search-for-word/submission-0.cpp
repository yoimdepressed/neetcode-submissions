class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word,int idx,vector<vector<int>>& visited) {
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1
        || board[i][j] != word[idx] || visited[i][j] == 1) return 0;

        visited[i][j] = 1;

        bool result  = dfs(board, i+1, j, word, idx+1, visited) ||
                       dfs(board, i, j+1, word, idx+1, visited) ||
                       dfs(board, i-1, j, word, idx+1, visited) ||
                       dfs(board, i, j-1, word, idx+1, visited);
        
        visited[i][j] = 0;
        return result;

    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
                    if(dfs(board,i,j,word,0,visited)) return true;
                }
            }
        }
        return false;
    }
};
