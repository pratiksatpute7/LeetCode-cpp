class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int maxProd = INT_MIN;
        for(int i = 0; i < size; i++) {
            int prod = 1;
            for(int j = i; j < size; j++) {
                prod *= nums[j];

                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};