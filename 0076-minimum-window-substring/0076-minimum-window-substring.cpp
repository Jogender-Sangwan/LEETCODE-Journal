#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t (ASCII 128 covers all English letters)
        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }

        int left = 0, right = 0;
        int required = t.length(); // Total characters still needed
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            // Expand the window by including s[right]
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;
            right++;

            // When all characters are matched, try to shrink the window from the left
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    startIdx = left;
                }

                // Remove s[left] from the window
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
