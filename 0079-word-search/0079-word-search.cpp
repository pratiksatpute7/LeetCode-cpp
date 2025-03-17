class Solution {
private:
    int rows, cols;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++){
                if(dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index){
        if(index == word.size()) {
            return true;
        }

        if(row < 0 || col < 0 || row >= rows || col >= cols || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;
        bool res = dfs(board, word, row + 1, col, index + 1) || 
                   dfs(board, word, row - 1, col, index + 1) ||
                   dfs(board, word, row, col + 1, index + 1) || 
                   dfs(board, word, row, col - 1, index + 1);
        visited[row][col] = false;
        return res;
    }
};