
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // Find the first occurrence of needle
        size_t found = haystack.find(needle);
        
        // If needle is not found, find() returns std::string::npos
        if (found == std::string::npos) {
            return -1;
        }
        
        // Return the index cast to an integer
        return static_cast<int>(found);
    }
};
