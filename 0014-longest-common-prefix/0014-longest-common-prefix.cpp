#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Guard clause: if the array is empty, return ""
        if (strs.empty()) return "";
        
        // Iterate through each character of the first string
        for (int i = 0; i < strs[0].length(); ++i) {
            char ch = strs[0][i];
            
            // Compare this character with the same position in all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If index exceeds the string length or character doesn't match
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    // Return the substring up to the current index
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If all characters matched, the first string itself is the LCP
        return strs[0];
    }
};
