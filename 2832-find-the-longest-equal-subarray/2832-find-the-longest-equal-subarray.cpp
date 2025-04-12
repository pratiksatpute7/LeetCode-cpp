class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, maxCount = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            maxCount = max(maxCount, freq[nums[right]]);

            // if deletions needed > k, shrink window
            while ((right - left + 1) - maxCount > k) {
                freq[nums[left]]--;
                left++;
            }

            res = max(res, maxCount);
        }

        return res;
    }
};