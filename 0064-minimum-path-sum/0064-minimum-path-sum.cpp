
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the first column (can only come from above)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // Initialize the first row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // Fill in the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // The bottom-right corner holds the minimum path sum
        return grid[m - 1][n - 1];
    }
};