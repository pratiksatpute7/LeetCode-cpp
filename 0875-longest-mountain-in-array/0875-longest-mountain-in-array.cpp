class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        int i = 1;

        while (i < n - 1) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // expand to left
                while (left > 0 && arr[left - 1] < arr[left]){
                    left--;
                } 

                // expand to right
                while (right < n - 1 && arr[right] > arr[right + 1]){
                    right++;
                }

                result = max(result, right - left + 1);
                i = right; // skip processed part
            } else {
                i++;
            }
        }

        return result;
    }
};