#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, int target, std::vector<int>& candidates, 
                   std::vector<int>& path, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion depth
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // Prune the branch if the current number is greater than the remaining target
            if (candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, path, result);
            path.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        backtrack(0, target, candidates, path, result);
        return result;
    }
};
