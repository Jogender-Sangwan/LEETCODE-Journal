/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // 1. Advance the fast pointer by n + 1 steps
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // 2. Move both pointers together until the fast pointer reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 3. Delete the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free memory in C++
        
        // 4. Return the new head
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node memory
        return newHead;
    }
};
