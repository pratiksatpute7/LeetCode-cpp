class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    int rows;
    int cols;

    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int perimeter = 0;
        visited[row][col] = 1;
        queue<pair<int, int>> q;

        q.push({row, col});

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || grid[nRow][nCol] == 0) {
                    perimeter++;
                } else if (!visited[nRow][nCol]) {
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int> (cols, 0));
        int perimeter = 0;
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(!visited[row][col] && grid[row][col] == 1) {
                    perimeter = bfs(row, col, grid, visited);
                }
            }
        }

        return perimeter;
    }
};