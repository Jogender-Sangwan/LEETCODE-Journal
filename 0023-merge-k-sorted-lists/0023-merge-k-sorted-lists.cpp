#include <vector>
#include <queue>

class Solution {
public:
    // Custom comparator to order the min-heap by node values
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Min-heap to keep track of the smallest node among the heads of all lists
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> minHeap;
        
        // Push the head of each non-empty list into the min-heap
        for (const auto* list : lists) {
            if (list != nullptr) {
                minHeap.push(const_cast<ListNode*>(list));
            }
        }
        
        // Dummy node to simplify the creation of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Process the min-heap until it is empty
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to the merged list
            tail->next = smallest;
            tail = tail->next;
            
            // If the popped node has a next element, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};

