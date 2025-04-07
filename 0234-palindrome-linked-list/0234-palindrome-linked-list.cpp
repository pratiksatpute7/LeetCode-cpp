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
    bool isPalindrome(ListNode* head) {

        stack<int> st;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            st.push(slow->val);
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        while(slow) {
            if(st.top() != slow -> val) {
                return false;
            } else {
                slow = slow -> next;
                st.pop();
            }
        }

        return true;

    }
};