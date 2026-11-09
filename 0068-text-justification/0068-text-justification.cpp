#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // Greedily pack words into the current line
            while (j < n && lineLen + words[j].length() + (j - i) <= maxWidth) {
                lineLen += words[j].length();
                j++;
            }

            std::string line = "";
            int numWords = j - i;
            int numSpaces = maxWidth - lineLen;

            // Case 1: Last line OR a line with only one word -> Left-justify
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                        numSpaces--;
                    }
                }
                line.append(numSpaces, ' '); // Pad remaining spaces at the end
            } 
            // Case 2: Fully justify regular lines
            else {
                int gaps = numWords - 1;
                int spacePerGap = numSpaces / gaps;
                int extraSpaces = numSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    // Distribute extra spaces to the leftmost gaps
                    int spacesToApply = spacePerGap + ((k - i) < extraSpaces ? 1 : 0);
                    line.append(spacesToApply, ' ');
                }
                line += words[j - 1]; // Append the last word of the line
            }

            result.push_back(line);
            i = j; // Move to the next line
        }

        return result;
    }
};
