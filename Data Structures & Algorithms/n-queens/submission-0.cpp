class Solution {
public:
    vector<vector<string>> boards;
    vector<string> board;

    vector<bool> usedCol;
    vector<bool> usedMainDiag;
    vector<bool> usedAntiDiag;

    void dfs(int row, int n) {
        // We successfully placed one queen in every row.
        if (row == n) {
            boards.push_back(board);
            return;
        }

        // Try placing the queen in every column of this row.
        for (int col = 0; col < n; col++) {
            int mainDiag = row - col + n - 1;
            int antiDiag = row + col;

            // Another queen attacks this position.
            if (usedCol[col] ||
                usedMainDiag[mainDiag] ||
                usedAntiDiag[antiDiag]) {
                continue;
            }

            // Choose: place the queen.
            board[row][col] = 'Q';

            usedCol[col] = true;
            usedMainDiag[mainDiag] = true;
            usedAntiDiag[antiDiag] = true;

            // Explore: place a queen in the next row.
            dfs(row + 1, n);

            // Undo: remove the queen.
            board[row][col] = '.';

            usedCol[col] = false;
            usedMainDiag[mainDiag] = false;
            usedAntiDiag[antiDiag] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        usedCol.assign(n, false);
        usedMainDiag.assign(2 * n - 1, false);
        usedAntiDiag.assign(2 * n - 1, false);

        dfs(0, n);

        return boards;
    }
};