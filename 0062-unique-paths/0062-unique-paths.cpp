#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use a 1D vector of size 'n' initialized to 1
        vector<int> dp(n, 1);
        
        // For each row from 1 to m - 1
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] is the value from the top cell (dp[j] from previous row)
                // dp[j-1] is the value from the left cell
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};

