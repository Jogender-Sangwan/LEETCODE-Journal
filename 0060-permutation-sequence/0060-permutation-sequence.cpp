#include <vector>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> factorials(n, 1);
        std::vector<int> numbers;
        
        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }
        
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }
        
        k--; // Convert to 0-indexed
        
        std::string result = "";
        
        for (int i = n - 1; i >= 0; --i) {
            int index = k / factorials[i];
            k %= factorials[i];
            
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
        }
        
        return result;
    }
};
