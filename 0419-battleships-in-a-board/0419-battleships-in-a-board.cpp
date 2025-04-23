class Solution {
public:
    int rows;
    int cols;
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                board[nRow][nCol] == 'X' && !visited[nRow][nCol]) {
                dfs(nRow, nCol, board, visited);
            }
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<int>> visited (rows, vector<int> (cols, 0));
        int battleShip = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(board[row][col] == 'X' && !visited[row][col]) {
                    dfs(row, col, board, visited);
                    battleShip ++;
                }
            }
        }

        return battleShip;
    }
};