#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        std::unordered_map<std::string, std::string> map;
        for (const auto& pair : knowledge) {
            map[pair[0]] = pair[1];
        }

        std::string result = "";
        int n = s.length();
        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                int j = i + 1;
                while (j < n && s[j] != ')') {
                    j++;
                }
                std::string key = s.substr(i + 1, j - i - 1);
                if (map.find(key) != map.end()) {
                    result += map[key];
                } else {
                    result += '?';
                }
                i = j + 1;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
