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

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        ListNode* tail = head;
        
        while(current && current -> val == val) {
            head = head -> next;
            current = head;
        }
        while(current != NULL) {
            while(current -> next != NULL && current -> next -> val == val) {
                current -> next = current -> next -> next;
            }
            current = current -> next;
        }

        return head;
    }
};