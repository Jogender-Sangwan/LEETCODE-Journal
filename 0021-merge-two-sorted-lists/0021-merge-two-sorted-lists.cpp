class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Traverse both lists until one runs out
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // The merged list starts at the next node of the dummy
        return dummy.next;
    }
};

