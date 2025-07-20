class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if(size == 0) return 0;
        if(size == 1) return nums[0];

        return max(robbing(nums, 0, size - 2), robbing(nums, 1, size - 1));
    }

    int robbing(vector<int>& nums, int start, int end) {
        int prev = 0, prev2 = 0;

        for(int i = start; i <= end; i++) {
            int curr = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    
};