class Solution {
public:

    // Top down with memoization
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size();
    //     int n = text2.size();

    //     vector<vector<int>> dp(m, vector<int> (n , -1));
    //     return maxLCS(m - 1, n - 1, text1, text2, dp);
    // }

    // int maxLCS(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp) {
    //     if(index1 < 0 || index2 < 0) {
    //         return 0;
    //     }

    //     if(dp[index1][index2] != -1) {
    //         return dp[index1][index2];
    //     }

    //     if(text1[index1] == text2[index2]) {
    //         return dp[index1][index2] = 1 + maxLCS(index1 - 1, index2 - 1, text1, text2, dp);
    //     } else {
    //         return dp[index1][index2] = max(maxLCS(index1 - 1, index2, text1, text2, dp), maxLCS(index1, index2 - 1, text1, text2, dp));
    //     }
    // }


    // // Bottom up/ Tabulation
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size();
    //     int n = text2.size();

    //     vector<vector<int>> dp(m + 1, vector<int> (n + 1 , 0));
    //     for(int i = 0; i < m; i++) {
    //         dp[i][0] = 0;
    //     }

    //     for(int j = 0; j < n; j++) {
    //         dp[0][j] = 0;
    //     }

    //     for(int i = 1; i <= m; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if(text1[i - 1] == text2[j - 1]) {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }


    // Bottom up/ Tabulation space optimised 
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prev[i] = 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                   curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};