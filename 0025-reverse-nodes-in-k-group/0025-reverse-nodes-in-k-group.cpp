/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes available to reverse
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head; // Less than k nodes left, leave them as is
            curr = curr->next;
        }
        
        // Step 2: Reverse the first k nodes
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: 'head' is now the tail of the reversed group.
        // Connect it to the head of the next reversed k-group.
        if (curr != nullptr) {
            head->next = reverseKGroup(curr, k);
        }
        
        // Step 4: 'prev' is the new head of the reversed group
        return prev;
    }
};
