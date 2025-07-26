class Solution {
public:
    // Reccurance and memoisation
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp (m , vector<int>(n, -1));
    //     return path(m - 1, n - 1, grid, dp);
    // }

    // int path(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    //     if(m == 0 && n == 0) {
    //         return grid[m][n];
    //     }
    //     if(m < 0 || n < 0) {
    //         return INT_MAX;
    //     }

    //     if(dp[m][n] != -1) {
    //         return dp[m][n];
    //     }

    //     int up = path(m - 1, n, grid, dp);
    //     int left = path(m, n - 1, grid, dp);

    //     return dp[m][n] = grid[m][n] + min(up, left);
    // }

    // Tabulation
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp (m , vector<int>(n, INT_MAX));
        
    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(i == 0 && j == 0) {
    //                 dp[i][j] = grid[i][j];
    //             } else {
    //                 int up = INT_MAX, left = INT_MAX;
    //                 if(i > 0) up = dp[i - 1][j];
    //                 if(j > 0) left  = dp[i][j - 1];
    //                 dp[i][j] = min(up, left) + grid[i][j];
    //             }
    //         }
    //     }

    //     return dp[m - 1][n - 1];
    // }

    // Tabulation and memory oprtimization
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev (n, 0);
        
        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                } else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = prev[j];
                    if(j > 0) left  = curr[j - 1];
                    curr[j] = min(up, left) + grid[i][j];
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }

};