class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> grid;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char element = board[i][j];
                if (element == '.') {
                    continue;
                }
                int idx = i/3*3+j/3+1;
                if (row[i].find(element) != row[i].end()
                || col[j].find(element) != col[j].end()
                || grid[idx].find(element) != grid[idx].end()) {
                    return false;
                } else {
                    row[i].insert(element);
                    col[j].insert(element);
                    grid[idx].insert(element);
                }
            }
        }
        return true;
    }
};