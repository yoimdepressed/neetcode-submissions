class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> mark_row;
    unordered_set<int> neg_diag;
    unordered_set<int> pos_diag;
    void solve(vector<string>& board,int col,int n) {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0;row < n;row++)
        {
            if(mark_row.find(row) == mark_row.end() && 
            neg_diag.find(row-col) == neg_diag.end() && 
            pos_diag.find(row+col) == pos_diag.end())
            {
                board[row][col] = 'Q';
                mark_row.insert(row);
                neg_diag.insert(row-col);
                pos_diag.insert(row+col);
                solve(board,col+1,n);
                board[row][col] = '.';
                mark_row.erase(row);
                neg_diag.erase(row-col);
                pos_diag.erase(row+col);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board,0,n);
        return ans;
    }
};
