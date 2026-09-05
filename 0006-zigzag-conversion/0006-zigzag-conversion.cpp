#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: If there is only 1 row or the string is shorter than rows,
        // the zigzag pattern is identical to the original string.
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }

        // Create an array of strings to represent each row
        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            rows[currentRow] += c;

            // Change direction when we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row based on the direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};

