class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0;
        int sum = 0;
        int best = INT_MAX;
        int res = INT_MAX;
        vector<int> min_len(arr.size(), INT_MAX);

        for(int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while(sum > target) {
                sum -= arr[left];
                left ++;
            }
            if (sum == target) {
                int curr_len = right - left + 1;

                // Combine with best seen so far (before current left)
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    res = min(res, curr_len + min_len[left - 1]);
                }

                best = min(best, curr_len);
            }
            // min len save the len of shortest sub arry that satisfis till current index
            min_len[right] = best;
        }

        return res == INT_MAX ? -1 : res;
    }
};