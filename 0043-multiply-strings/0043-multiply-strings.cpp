#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        // Handle the edge case where either number is "0"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int m = num1.size();
        int n = num2.size();
        // Vector to store intermediate products and final digits
        std::vector<int> result(m + n, 0);
        
        // Loop from right to left for both strings
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Multiply single digits
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Determine indices in the result array
                int p1 = i + j;
                int p2 = i + j + 1;
                
                // Add current multiplication to the existing value at position p2
                int sum = mul + result[p2];
                
                // Update positions with carry and remainder
                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }
        
        // Build the final string representation, skipping leading zeros
        std::string productStr = "";
        for (int num : result) {
            if (!(productStr.empty() && num == 0)) {
                productStr.push_back(num + '0');
            }
        }
        
        return productStr;
    }
};

