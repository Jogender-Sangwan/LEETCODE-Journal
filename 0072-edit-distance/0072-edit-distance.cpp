#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] represents the minimum operations to convert word1[0..i-1] to word2[0..j-1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // Base cases: converting an empty string to word2 or vice versa
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i; // Delete all characters from word1
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j; // Insert all characters to match word2
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                } else {
                    dp[i][j] = 1 + std::min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};
