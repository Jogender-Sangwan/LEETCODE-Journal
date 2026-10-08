#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        // Generate the sequence iteratively up to n
        std::string current = "1";
        for (int i = 2; i <= n; ++i) {
            std::string next_str = "";
            int len = current.length();
            
            int j = 0;
            while (j < len) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                // Append the count and the character itself
                next_str += std::to_string(count) + current[j];
                j++;
            }
            current = next_str;
        }
        
        return current;
    }
};
