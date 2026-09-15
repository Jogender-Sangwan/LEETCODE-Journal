#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array fixing the first element
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: If the smallest number is greater than 0, 
            // no three numbers can sum up to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Use two pointers for the remaining elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicate values for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Sum is too small, move left pointer rightward
                } 
                else {
                    right--; // Sum is too large, move right pointer leftward
                }
            }
        }
        
        return result;
    }
};
