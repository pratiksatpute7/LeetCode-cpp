class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int maxLen = 1;
        int left = 0;

        for (int right = 1; right < n; right++) {
            int cmp = compare(arr[right - 1], arr[right]);

            if (cmp == 0) {
                left = right;
                // check if its alternating if not that means sequence end 
            } else if (right == n - 1 || cmp * compare(arr[right], arr[right + 1]) != -1) {
                // End of turbulent pattern
                maxLen = max(maxLen, right - left + 1);
                left = right;
            }
        }

        return maxLen;
    }

    // Helper: returns 1 if a > b, -1 if a < b, 0 if equal
    int compare(int a, int b) {
        if (a > b) return 1;
        if (a < b) return -1;
        return 0;
    }
};
