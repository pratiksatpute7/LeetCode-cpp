class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = matrix.size();
        int low = matrix[0][0];
        int high = matrix[size - 1][size - 1];

        while(low < high) {
            int mid = low + (high - low) / 2;

            int count = countLessEqual(matrix, mid);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }

    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int n = matrix.size();
        int row = n - 1, col = 0;

        while(row >= 0 && col < n) {
            if(matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
};