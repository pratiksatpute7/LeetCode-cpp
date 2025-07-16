class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> hor(rows, vector<int>(cols, 0));
        vector<vector<int>> ver(rows, vector<int>(cols, 0));
        int maxLen = 0;


        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 1) {
                    hor[row][col] = (col > 0 ? hor[row][col - 1] : 0) + 1;
                    ver[row][col] = (row > 0 ? ver[row - 1][col] : 0) + 1;
                }
            }
        }

        for(int row = rows - 1; row >= 0; row--) {
            for(int col = cols - 1; col >= 0; col--) {
                int len = min(hor[row][col], ver[row][col]);

                while (len > 0) {
                    if (hor[row - len + 1][col] >= len && ver[row][col - len + 1] >= len) {
                        maxLen = max(maxLen, len);
                        break;
                    }
                    len--;
                }
            }
        }

        return maxLen * maxLen;
    }
};