class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int count = 0;

        while (head) {
//             if (current node is in nums &&
//    (next node is either null or not in nums))
            if (numSet.count(head->val) &&
                (!head->next || !numSet.count(head->next->val))) {
                count++;
            }
            head = head->next;
        }

        return count;
    }
};
