class Solution {
public:
    int mySqrt(int x) {
        // Base cases
        if (x == 0 || x == 1) {
            return x;
        }
        
        int left = 1, right = x, ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use division to prevent integer overflow (mid * mid <= x)
            if (mid <= x / mid) {
                ans = mid;      // Found a valid candidate, save it
                left = mid + 1; // Try to find a larger value
            } else {
                right = mid - 1; // mid is too large, look on the left side
            }
        }
        
        return ans;
    }
};
