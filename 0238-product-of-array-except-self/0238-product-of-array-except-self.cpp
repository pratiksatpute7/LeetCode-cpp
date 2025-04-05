class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result (size, 1);
        int prefix = 1;
        int suffix = 1;

        for(int i = 0; i < size; i++) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        for(int i = size - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};