#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        int n = nums.size();

        // Traverse up to the second-to-last element
        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // Early exit if we can already reach the last index
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};
