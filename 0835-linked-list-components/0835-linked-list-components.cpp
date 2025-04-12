class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int count = 0;

        while (head) {
            // head is in nums, and either next is null or next is not in nums
            if (numSet.count(head->val) &&
                (!head->next || !numSet.count(head->next->val))) {
                count++;
            }
            head = head->next;
        }

        return count;
    }
};
