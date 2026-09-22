#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current, int openCount, int closeCount, int n) {
        // Base case: If the current combination is complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Decision 1: Add an opening parenthesis if we haven't reached the limit 'n'
        if (openCount < n) {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }

        // Decision 2: Add a closing parenthesis if it won't exceed the opening ones
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }
};

