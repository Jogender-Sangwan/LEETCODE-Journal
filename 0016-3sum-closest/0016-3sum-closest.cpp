#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use the two-pointer technique
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2]; // Initialize with the first possible triplet sum
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // If we find an exact match, return it immediately
                if (current_sum == target) {
                    return current_sum;
                }
                
                // Update closest_sum if the current_sum is closer to the target
                if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // Move pointers based on how current_sum compares to target
                if (current_sum < target) {
                    ++left; // We need a larger sum
                } else {
                    --right; // We need a smaller sum
                }
            }
        }
        
        return closest_sum;
    }
};
