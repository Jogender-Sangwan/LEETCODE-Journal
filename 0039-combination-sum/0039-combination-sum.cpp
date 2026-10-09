#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& candidates, int target, int start, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                // Since candidates are sorted, further elements will also be too large
                break;
            }
            current.push_back(candidates[i]);
            // Pass 'i' instead of 'i + 1' to allow reusing the same element
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
