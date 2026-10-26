#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort intervals by their start time
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the last merged interval
            if (merged.back()[1] >= intervals[i][0]) {
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap, push the current interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
