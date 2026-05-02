/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) return NULL;

    // Dummy node for sorted list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;  // store next node

        // Find position in sorted list
        struct ListNode* prev = dummy;

        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert current node
        curr->next = prev->next;
        prev->next = curr;

        curr = next;  // move to next node
    }

    return dummy->next;
}