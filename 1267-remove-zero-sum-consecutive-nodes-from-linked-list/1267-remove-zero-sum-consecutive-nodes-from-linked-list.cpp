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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        int prefixSum = 0;

        while(curr) {
            prefixSum += curr -> val;
            mp[prefixSum] = curr;
            curr = curr -> next;
        }

        curr = dummy;
        prefixSum = 0;

        while(curr) {
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
            curr = curr->next;
        }

        return dummy->next;

    }
};