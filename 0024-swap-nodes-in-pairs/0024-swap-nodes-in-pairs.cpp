/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to handle head updates easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        // Traverse while there are at least two nodes to swap
        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            // Change pointers to swap the pair
            first->next = second->next;
            current->next = second;
            current->next->next = first;

            // Move pointer forward by two nodes
            current = current->next->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};
