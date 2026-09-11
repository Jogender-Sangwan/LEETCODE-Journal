#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Pairs of values and their corresponding Roman numeral symbols in descending order
        const std::vector<std::pair<int, std::string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        
        // Loop through the map and greedily build the Roman numeral
        for (const auto& pair : romanMap) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        
        return result;
    }
};

