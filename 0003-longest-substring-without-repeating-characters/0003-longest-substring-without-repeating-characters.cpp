#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Vector to store the last seen index of each character
        // ASCII size is 128 to cover letters, digits, symbols, and spaces
        std::vector<int> lastIndex(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char current = s[right];
            
            // If the character was seen before and is inside the current window
            if (lastIndex[current] >= left) {
                left = lastIndex[current] + 1; // Move left boundary past the last seen duplicate
            }
            
            // Update the last seen index of the current character
            lastIndex[current] = right;
            
            // Calculate the current window size and update maximum length
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
