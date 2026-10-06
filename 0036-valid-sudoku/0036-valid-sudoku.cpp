#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                char val = board[i][j];
                std::string rowKey = std::string(1, val) + "@row" + std::to_string(i);
                std::string colKey = std::string(1, val) + "@col" + std::to_string(j);
                std::string boxKey = std::string(1, val) + "@box" + std::to_string(i / 3) + std::to_string(j / 3);

                if (!seen.insert(rowKey).second || 
                    !seen.insert(colKey).second || 
                    !seen.insert(boxKey).second) {
                    return false; // Duplicate found
                }
            }
        }
        return true;
    }
};
