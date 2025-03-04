class Solution {

private:
    void subSet(int index, vector<int>& ds, vector<vector<int>>& set, vector<int>& nums, int n) {
        // base case if index goes beyond size 
        if(index == n) {
            set.push_back(ds);
            return;
        }

        // Take current index
        ds.push_back(nums[index]);
        subSet(index + 1, ds, set, nums, n);

        // sub tree for not take current index
        ds.pop_back();
        subSet(index + 1, ds, set, nums, n);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> set;
        vector<int> ds;
        subSet(0, ds, set, nums, nums.size());

        return set;
    }
};