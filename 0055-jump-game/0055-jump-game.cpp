#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If current index is greater than the maximum reachable index, return false
            if (i > maxReach) {
                return false;
            }
            // Update the maximum reachable index
            maxReach = max(maxReach, i + nums[i]);
            // If we can already reach or exceed the last index, return true
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
