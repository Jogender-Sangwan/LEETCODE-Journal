#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            
            if (std::isdigit(ch)) {
                seenDigit = true;
            } 
            else if (ch == '+' || ch == '-') {
                // A sign is only valid at the start or immediately after 'e'/'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (ch == '.') {
                // A dot is invalid if we've already seen a dot or an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                // An exponent is invalid if we've already seen one or haven't seen a digit yet
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to ensure an integer follows the exponent
            } 
            else {
                // Any other character (like 'a', 'b', space, etc.) is invalid
                return false;
            }
        }
        
        // The string is valid only if it ends with a valid digit sequence
        return seenDigit;
    }
};
