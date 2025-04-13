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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy -> next = head;
        if(head == NULL) {
            return NULL;
        }

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all duplicates
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Connect prev to node after the last duplicate
                prev->next = head->next;
            } else {
                // No duplicate, move prev
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
