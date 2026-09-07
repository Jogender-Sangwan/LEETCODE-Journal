#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // If string is all whitespace
        if (i == n) {
            return 0;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        // Step 3: Convert digits and handle overflow/underflow
        long long result = 0; // Use long long to detect overflow during calculation
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Apply sign and check bounds immediately to prevent overflow
            long long signed_result = result * sign;
            if (signed_result > INT_MAX) {
                return INT_MAX;
            }
            if (signed_result < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};

