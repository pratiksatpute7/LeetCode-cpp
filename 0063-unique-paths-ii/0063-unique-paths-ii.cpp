class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, -1));

        if(obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        return path(obstacleGrid, m - 1, n - 1, dp);
        
    }

    int path(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>&dp) {

        if(m == 0 && n == 0) {
            return 1;
        }

        if(m < 0 || n < 0) {
            return 0;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        int left = 0;
        int up = 0;

        if(m - 1 >= 0 && obstacleGrid[m - 1][n] == 0) {
            up = path(obstacleGrid, m - 1, n, dp);
        }

        if(n - 1 >= 0 && obstacleGrid[m][n - 1] == 0) {
            left = path(obstacleGrid, m, n - 1, dp);
        }

        return dp[m][n] = left + up;
    }
};