class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int size = nums.size();
    //     vector<int> dp(size, -1);
    //     dp[0] = nums[0];
    //     if(size > 1) {
    //         dp[1] =  max(nums[0], nums[1]);
    //     }

    //     for(int i = 2; i < size; i++) {
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    //     }

    //     return dp[size - 1];
    // }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        int prev2 = nums[0];                      // house 0
        int prev = max(nums[0], nums[1]);         // max of house 0 or 1
        for(int i = 2; i < size; i++) {
           int curr = max(prev2 + nums[i], prev);
           prev2 = prev;
           prev = curr;
        }

        return prev;
    }

    
};