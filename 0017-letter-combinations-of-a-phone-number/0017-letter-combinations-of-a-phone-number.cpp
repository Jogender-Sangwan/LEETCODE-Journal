#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        // Return an empty list if the input string is empty
        if (digits.empty()) {
            return {};
        }

        // Map digits '0'-'9' to their corresponding letters
        std::vector<std::string> phoneMap = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",  "pqrs", 
            "tuv",  "wxyz"
        };

        std::vector<std::string> result;
        std::string currentCombination = "";
        
        // Start the backtracking process
        backtrack(digits, 0, phoneMap, currentCombination, result);
        return result;
    }

private:
    void backtrack(const std::string& digits, int index, const std::vector<std::string>& phoneMap, 
                   std::string& currentCombination, std::vector<std::string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        // Get the letters corresponding to the current digit
        std::string letters = phoneMap[digits[index] - '0'];

        // Loop through the letters and recurse
        for (char c : letters) {
            currentCombination.push_back(c);                 // Choose
            backtrack(digits, index + 1, phoneMap, currentCombination, result); // Recurse
            currentCombination.pop_back();                  // Backtrack (Undo choice)
        }
    }
};
