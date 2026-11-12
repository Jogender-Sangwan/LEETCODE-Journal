#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;

        while (std::getline(ss, token, '/')) {
            if (token.empty() || token == ".") {
                // Ignore empty strings (from multiple slashes) and current directory '.'
                continue;
            } else if (token == "..") {
                // Go to the parent directory if the stack is not empty
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Any other token (including '...', '....', or valid names) is pushed onto the stack
                stack.push_back(token);
            }
        }

        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }

        // If result is empty, it means we are at the root '/'
        return result.empty() ? "/" : result;
    }
};

