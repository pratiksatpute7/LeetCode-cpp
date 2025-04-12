class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int left = 0;
        long long sum = 0;
        int window = k + k + 1;
        int avg = 0;
        vector<int> avgArr (nums.size(), -1);

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(right - left + 1 > window) {
                sum -= nums[left];
                left++;
            }

            if(window == right - left + 1) {
                int index = (left + right) / 2;
                avgArr[index] = sum / window;
            }
        }

        return avgArr;
    }
};