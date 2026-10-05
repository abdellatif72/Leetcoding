class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool valid(int x, int y, vector<vector<char>>& board, char target) {
        return x >= 0 && x < board.size() &&
               y >= 0 && y < board[0].size() &&
               board[x][y] == target;
    }

    bool dfs(int x, int y, int idx, vector<vector<char>>& board, string& word) {
        if (idx == word.size() - 1)
            return true;

        char original = board[x][y];
        board[x][y] = '#';

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (valid(nx, ny, board, word[idx + 1])) {
                if (dfs(nx, ny, idx + 1, board, word))
                    return true;
            }
        }

        board[x][y] = original;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (valid(i, j, board, word[0])) {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};