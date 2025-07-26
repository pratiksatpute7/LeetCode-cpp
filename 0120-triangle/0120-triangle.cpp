class Solution {
public:
    // Recurrsiove with memoization still time limit exceeeded
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return path(0, 0, triangle, n, dp);
    // }

    // int path(int i, int j, vector<vector<int>>& triangle, int n,  vector<vector<int>>& dp) {
    //     if(i == n - 1) {
    //         return triangle[i][j];
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int down = triangle[i][j] + path(i + 1, j, triangle, n, dp);
    //     int diag = triangle[i][j] + path(i + 1, j + 1, triangle, n, dp);

    //     return dp[i][j] = min(down, diag);
    // }

    // Tablulation
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
        
    //     for(int i = 0; i < n; i ++) {
    //         dp[n - 1][i] = triangle[n - 1][i];
    //     }

    //     for(int i = n - 2; i >= 0; i--) {
    //         for(int j = i; j >= 0; j--) {

    //             if(i == n - 1) {
    //                 dp[i][j] = triangle[i][j];
    //             }
    //             int down = triangle[i][j] + dp[i + 1][j];
    //             int diag = triangle[i][j] + dp[i + 1][j + 1];

    //             dp[i][j] = min(down, diag);
    //         }
    //     }

    //     return dp[0][0];
    // }

// tabulation with space optimizqtion
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);
        
        for(int i = 0; i < n; i ++) {
            prev[i] = triangle[n - 1][i];
        }

        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for(int j = i; j >= 0; j--) {

                if(i == n - 1) {
                    curr[j] = triangle[i][j];
                }
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j + 1];

                curr[j] = min(down, diag);
            }

            prev = curr;
        }

        return prev[0];
    }

};