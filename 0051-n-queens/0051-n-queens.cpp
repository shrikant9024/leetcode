class Solution {
public:
    bool nqueen(int row, int col, vector<string>& board, int n) {
        // Check upper diagonal
        int drow = row, dcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        // Check lower diagonal
        row = drow, col = dcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        // Check left column
        col = dcol;
        while (col >= 0) {
            if (board[drow][col] == 'Q') return false;
            col--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& res, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (nqueen(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        solve(0, board, res, n);
        return res;
    }
};
