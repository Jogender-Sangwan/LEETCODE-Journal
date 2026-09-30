#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        int s_len = s.length();

        if (s_len < total_len) return result;

        std::unordered_map<std::string, int> word_count;
        for (const std::string& word : words) {
            word_count[word]++;
        }

        // Iterate through each possible offset up to word_len
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string, int> seen_words;
            int count = 0;

            while (right + word_len <= s_len) {
                std::string sub = s.substr(right, word_len);
                right += word_len;

                if (word_count.count(sub)) {
                    seen_words[sub]++;
                    count++;

                    // If a word appears more times than it does in words, shrink from left
                    while (seen_words[sub] > word_count[sub]) {
                        std::string left_sub = s.substr(left, word_len);
                        seen_words[left_sub]--;
                        left += word_len;
                        count--;
                    }

                    // If we matched all words, record the starting index
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if word is not in words
                    seen_words.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
