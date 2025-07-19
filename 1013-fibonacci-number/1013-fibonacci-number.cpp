class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        if (n > 0) dp[1] = 1;    
        return temp(n, dp);
    }

    int temp(int n, vector<int>& dp) {
        // if(n == 0) {
        //     return 0;
        // }

        // if(n == 1) {
        //     return 1;
        // }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = temp(n - 1, dp) + temp(n - 2, dp);

        return dp[n];
    }
};