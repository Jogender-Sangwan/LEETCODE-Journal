#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1;
        int matchIdx = 0;
        
        while (i < s.length()) {
            // Case 1: Direct match or '?' wildcard
            if (j < p.length() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Case 2: '*' wildcard encountered
            else if (j < p.length() && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++; // Try matching empty sequence first
            }
            // Case 3: Mismatch, but we have seen a '*' before
            // Backtrack to the last '*' and extend its match by 1 character of s
            else if (starIdx != -1) {
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
            }
            // Case 4: Mismatch and no '*' to fall back on
            else {
                return false;
            }
        }
        
        // Check if any remaining characters in pattern are not '*'
        while (j < p.length() && p[j] == '*') {
            j++;
        }
        
        return j == p.length();
    }
};
