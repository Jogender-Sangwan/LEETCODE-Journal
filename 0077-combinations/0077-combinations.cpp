#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, std::vector<int>& current,
                   std::vector<std::vector<int>>& result) {
        if (static_cast<int>(current.size()) == k) {
            result.push_back(current);
            return;
        }

        int need = k - static_cast<int>(current.size());
        int max_start = n - need + 1;
        for (int i = start; i <= max_start; ++i) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back();
        }
    }
};
