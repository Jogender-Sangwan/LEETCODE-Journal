#include <iostream>
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false); // r - c + n
        std::vector<bool> diag2(2 * n, false); // r + c

        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int r, int n, std::vector<bool>& cols, 
                   std::vector<bool>& diag1, std::vector<bool>& diag2, int& count) {
        if (r == n) {
            count++;
            return;
        }
        for (int c = 0; c < n; ++c) {
            int d1 = r - c + n;
            int d2 = r + c;
            if (cols[c] || diag1[d1] || diag2[d2]) {
                continue;
            }
            cols[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(r + 1, n, cols, diag1, diag2, count);

            cols[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};