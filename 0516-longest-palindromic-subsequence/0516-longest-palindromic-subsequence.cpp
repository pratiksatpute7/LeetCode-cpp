class Solution {
public:
    // recurrsiove with memoization
    // int longestPalindromeSubseq(string s) {
    //     string s2 = s;
    //     reverse(s2.begin(), s2.end());
    //     int len = s.size();
    //     vector<vector<int>> dp(len, vector<int>(len, - 1));

    //     return LPS(len - 1, len - 1, s, s2, dp);

    // }

    // int LPS(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    //     if(i < 0 || j < 0){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     if(s1[i] == s2[j]) {
    //         return dp[i][j] = 1 + LPS(i - 1, j - 1, s1, s2, dp);
    //     } else {
    //         return dp[i][j] = max(LPS(i - 1, j, s1, s2, dp), LPS(i, j - 1, s1, s2, dp));
    //     }
    // }

    // Tabulation

    // int longestPalindromeSubseq(string s) {
    //     string s2 = s;
    //     reverse(s2.begin(), s2.end());
    //     int len = s.size();
    //     vector<vector<int>> dp(len + 1, vector<int>(len + 1, - 1));

    //      for(int i = 0; i < len; i++) {
    //         dp[i][0] = 0;
    //         dp[0][i] = 0;
    //     }

    //     for(int i = 1; i <= len; i++) {
    //         for(int j = 1; j <= len; j++) {
    //             if(s[i - 1] == s2[j - 1]) {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }

    //     return dp[len][len];

    // }

    //Tabulation with space optimisation

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int len = s.size();
        vector<int> prev(len + 1, 0);

        for(int i = 1; i <= len; i++) {
            vector<int> curr(len + 1, 0);
            for(int j = 1; j <= len; j++) {
                if(s[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[len];

    }


};