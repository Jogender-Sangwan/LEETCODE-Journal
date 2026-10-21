#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.'));
        
        // Trackers for columns and diagonals
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n - 1, false); // For tracking row - col
        std::vector<bool> diag2(2 * n - 1, false); // For tracking row + col
        
        backtrack(0, n, board, solutions, cols, diag1, diag2);
        return solutions;
    }

private:
    void backtrack(int row, int n, std::vector<std::string>& board, 
                   std::vector<std::vector<std::string>>& solutions,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        // Base case: All queens are successfully placed
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            // Check if the current position is under attack
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }
            
            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            
            // Move to the next row
            backtrack(row + 1, n, board, solutions, cols, diag1, diag2);
            
            // Backtrack (remove the queen)
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};
