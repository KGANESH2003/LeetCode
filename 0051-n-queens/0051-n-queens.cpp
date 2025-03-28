class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Initialize an empty board
        backtrack(board, 0, n, result);
        return result;
    }

private:
    void backtrack(vector<string>& board, int row, int n, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);  // Found a valid board configuration
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';  // Place queen
                backtrack(board, row + 1, n, result);  // Move to the next row
                board[row][col] = '.';  // Backtrack: Remove the queen
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col, int n) {
        // Check the column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check the top-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check the top-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;  // It's safe to place the queen
    }
};
