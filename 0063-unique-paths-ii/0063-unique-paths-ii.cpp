#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the start or end is blocked, 0 paths are possible.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        // Use a 1D DP array of size n, initialized to 0
        std::vector<long long> dp(n, 0);
        dp[0] = 1; // 1 way to be at the starting point
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks the path
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Ways from top (dp[j]) + ways from left (dp[j-1])
                }
            }
        }
        
        return dp[n - 1];
    }
};
