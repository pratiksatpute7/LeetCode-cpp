class Solution {
public:


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int out = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(!visited[row][col] && grid2[row][col] == 1) {
                    int result = true;
                    dfs(grid1, grid2, visited, result, row, col, rows, cols);

                    if(result) {
                        out++;
                    }
                }
            }
        }

        return out;
    }

    void dfs(
        vector<vector<int>>& grid1, 
        vector<vector<int>>& grid2, 
        vector<vector<int>>& visited,
        int& result,  
        int row,
        int col,
        int rows,
        int cols) {

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            visited[row][col] = 1;
            queue<pair<int, int>> q;

            q.push({row, col});

            while(!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                if(grid1[row][col] == 0) {
                    result = false;
                }
                q.pop();

                for(int index = 0; index < 4; index++) {
                    int nRow = row + delRow[index];
                    int nCol = col + delCol[index];

                    if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && !visited[nRow][nCol] && grid2[nRow][nCol] == 1) {
                        visited[nRow][nCol] = 1;

                        q.push({nRow, nCol});
                    }
                }
            }
    }
};