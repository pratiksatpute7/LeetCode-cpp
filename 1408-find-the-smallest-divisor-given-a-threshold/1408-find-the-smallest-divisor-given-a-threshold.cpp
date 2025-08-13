class Solution {
public:
    int isValidSum(vector<int> nums, int mid) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += ceil((double)(nums[i] / (double)(mid)));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
        if (n > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result = -1;


        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValidSum(nums, mid) <= threshold) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};