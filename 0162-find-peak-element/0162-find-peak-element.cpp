class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Ascending → go right
                left = mid + 1;
            } else {
                // Descending → go left
                right = mid;
            }
        }

        return left; // or right; both point to a peak
    }
};