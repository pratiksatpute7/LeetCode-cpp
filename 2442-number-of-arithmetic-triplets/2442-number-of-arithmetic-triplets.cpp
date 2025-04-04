class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // int result = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(i > 0 && nums[i] == nums[i - 1]) continue;
        //     int left = i + 1;
        //     int right = nums.size() - 1;

        //     while(left < right) {
        //         int sum1 = nums[left] - nums[i];
        //         int sum2 = nums[right] - nums[left];
        //         if(sum1 == diff && sum2 == diff) {
        //             result ++;
        //             left++;
        //             right--;

        //         }else if(sum1<diff){
        //             left++;
        //         }else{
        //             right--;
        //         }
        //     }
        // }

        // return result;
        unordered_set<int> seen(nums.begin(), nums.end());
        int count = 0;
        for (int num : nums) {
            if (seen.count(num + diff) && seen.count(num + 2 * diff)) {
                count++;
            }
        }
        return count;
    }
};