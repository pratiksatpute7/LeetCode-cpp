class Solution {
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp (m, vector<int>(n, -1));

    //     if(obstacleGrid[m - 1][n - 1] == 1) {
    //         return 0;
    //     }

    //     return path(obstacleGrid, m - 1, n - 1, dp);
        
    // }

    // int path(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>&dp) {

    //     if(m == 0 && n == 0) {
    //         return 1;
    //     }

    //     if(m < 0 || n < 0) {
    //         return 0;
    //     }
    //     if(dp[m][n] != -1) {
    //         return dp[m][n];
    //     }
    //     int left = 0;
    //     int up = 0;

    //     if(m - 1 >= 0 && obstacleGrid[m - 1][n] == 0) {
    //         up = path(obstacleGrid, m - 1, n, dp);
    //     }

    //     if(n - 1 >= 0 && obstacleGrid[m][n - 1] == 0) {
    //         left = path(obstacleGrid, m, n - 1, dp);
    //     }

    //     return dp[m][n] = left + up;
    // }

    // Tabulation 
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp (m, vector<int>(n, -1));

    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(i == 0 && j == 0) {
    //                 dp[i][j] = (obstacleGrid[i][j] == 0) ? 1 : 0;
    //                 continue;
    //             }

    //             int left = 0;
    //             int up = 0;

    //             if(obstacleGrid[i][j] == 0) {
    //                 if(i > 0) {
    //                     up = dp[i - 1][j];
    //                 }

    //                 if(j > 0) {
    //                     left = dp[i][j - 1];
    //                 }

    //                 dp[i][j] = left + up;

    //             } else {
    //                 dp[i][j] = 0;
    //             }

               
                
    //         }
    //     }

    //     return dp[m - 1][n - 1];
        
    // }
    // Tabulation and space optimisation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev (n, 0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = (obstacleGrid[i][j] == 0) ? 1 : 0;
                    continue;
                }
                int left = 0;
                int up = 0;

                if(obstacleGrid[i][j] == 0) {
                    if(i > 0) {
                        up = prev[j];
                    }
                    if(j > 0) {
                        left = curr[j - 1];
                    }
                    curr[j] = left + up;
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
        
    }
};