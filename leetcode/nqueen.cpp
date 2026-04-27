class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }

private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, 
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (cols[c] || diag1[r + c] || diag2[r - c + n]) continue;
            
            board[r][c] = 'Q';
            cols[c] = diag1[r + c] = diag2[r - c + n] = 1;
            
            backtrack(r + 1, n, board, res, cols, diag1, diag2);
            
            board[r][c] = '.';
            cols[c] = diag1[r + c] = diag2[r - c + n] = 0;
        }
    }
};
