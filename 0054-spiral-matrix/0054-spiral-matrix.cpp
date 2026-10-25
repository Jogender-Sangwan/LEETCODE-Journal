#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1. Move from left to right across the top row
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // 2. Move from top to bottom down the right column
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // Check if there are still valid rows remaining
            if (top <= bottom) {
                // 3. Move from right to left across the bottom row
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Check if there are still valid columns remaining
            if (left <= right) {
                // 4. Move from bottom to top up the left column
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return result;
    }
};

