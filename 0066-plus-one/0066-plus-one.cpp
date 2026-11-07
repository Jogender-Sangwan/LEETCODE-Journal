#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from right to left (least significant digit to most)
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry needed, return immediately
            }
            digits[i] = 0; // If it's 9, it becomes 0 and carries 1 to the next digit
        }
        
        // If all digits were 9 (e.g., [9, 9] -> [1, 0, 0])
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
