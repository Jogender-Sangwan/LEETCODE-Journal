#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate the width between the two lines
            int width = right - left;
            
            // The water level is limited by the shorter line
            int current_height = std::min(height[left], height[right]);
            
            // Calculate current area and update maximum water if it's larger
            int current_water = width * current_height;
            max_water = std::max(max_water, current_water);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};

