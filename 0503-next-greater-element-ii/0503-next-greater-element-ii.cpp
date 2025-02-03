class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> st;
        vector<int> res(nums.size(), -1);

        for(int i = 0; i < (nums.size() * 2); i++) {

            // Circular loop calculation
            int index = i % nums.size();
            while(!st.empty() && nums[index] > st.top().first) {
                auto pair = st.top();
                st.pop();
                res[pair.second] = nums[index];
            }
            st.push({nums[index], index});
        }
        return res;
    }
};