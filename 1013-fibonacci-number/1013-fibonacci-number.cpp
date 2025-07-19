class Solution {
public:
    // int fib(int n) {
    //     vector<int> dp(n + 1, -1);
    //     dp[0] = 0;
    //     if (n > 0) dp[1] = 1;    
    //     return temp(n, dp);
    // }

    // Tabluation 
    // int fib(int n) {
    //     vector<int> dp(n + 1, -1);
    //     dp[0] = 0;
    //     if (n > 0) dp[1] = 1;    

    //     for(int i = 2; i <= n; i ++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }


    // Tabluation space optimization
    int fib(int n) {
        // vector<int> dp(n + 1, -1);
        // dp[0] = 0;
        int prev1 = 1;
        int prev2 = 0;
        // if (n > 0) dp[1] = 1;    

        for(int i = 0; i < n; i ++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev2;
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