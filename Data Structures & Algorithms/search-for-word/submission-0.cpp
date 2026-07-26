class Solution {
public:
    bool dfs(
        vector<vector<char>>& board,
        string& word,
        int row,
        int col,
        int index,
        vector<vector<bool>>& visited
    ) {
        // We matched every character in the word.
        if (index == word.size()) {
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();

        // Invalid position.
        if (row < 0 || row >= rows ||col < 0 || col >= cols) {
            return false;
        }

        // Cannot reuse a cell.
        if (visited[row][col]) {
            return false;
        }

        // Current cell does not match the needed character.
        if (board[row][col] != word[index]) {
            return false;
        }

        // Choose this cell.
        visited[row][col] = true;

        bool found =
            dfs(board, word, row - 1, col, index + 1, visited) ||
            dfs(board, word, row + 1, col, index + 1, visited) ||
            dfs(board, word, row, col - 1, index + 1, visited) ||
            dfs(board, word, row, col + 1, index + 1, visited);

        // Undo the choice.
        visited[row][col] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (dfs(board, word, row, col, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};