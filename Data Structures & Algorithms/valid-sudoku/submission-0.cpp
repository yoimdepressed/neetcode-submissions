class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> map;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (map[i].count(board[i][j]) > 0)
                        return false;
                    map[i].insert(board[i][j]);
                }
            }
        }

        unordered_map<int, unordered_set<char>> map2;

        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (map2[j].count(board[i][j]) > 0)
                        return false;
                    map2[j].insert(board[i][j]);
                }
            }
        }

        unordered_map<int, unordered_set<char>> map3;

        for (int box = 0; box < 9; box++) {
            int sr = (box / 3) * 3;
            int sc = (box % 3) * 3;

            for (int i = sr; i < sr + 3; i++) {
                for (int j = sc; j < sc + 3; j++) {
                    if (board[i][j] != '.') {
                        if (map3[box].count(board[i][j]) > 0)
                            return false;
                        map3[box].insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};