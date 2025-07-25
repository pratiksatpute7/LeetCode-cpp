class Solution {
public:
    int path(int m, int n, vector<vector<int>>& dp) {
        if(m == 0 && n == 0) {
            return 1;
        }

        if(m < 0 || n < 0) {
            return 0;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int left = path(m , n - 1, dp);
        int up = path(m - 1, n, dp);

        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) {
            return 1;
        }
        vector<vector<int>> dp(m , vector<int>(n , -1));
    //    return path(m - 1, n - 1);
        path(m - 1, n - 1, dp);
        return dp[m - 1][n -1];
    }
};