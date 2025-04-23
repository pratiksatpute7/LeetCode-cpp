class Solution {
public:
    vector<vector<int>> result;
    int rows, cols;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};


    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        ocean[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                heights[row][col] <= heights[nRow][nCol] && !ocean[nRow][nCol]) {
                    ocean[nRow][nCol] = 1;
                    dfs(nRow, nCol, heights, ocean);
                }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        for(int col = 0; col < cols; col++){
            dfs(0, col, heights, pacific);
            dfs(rows - 1, col, heights, atlantic);
        }

        for(int row = 0; row < rows; row++){
            dfs(row, 0, heights, pacific);
            dfs(row, cols - 1, heights, atlantic);
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }

        return result;
    }
};