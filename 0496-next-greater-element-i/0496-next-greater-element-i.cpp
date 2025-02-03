class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> res(nums1.size(), -1);

        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]] = i;
        }

        for(int i = 0; i < nums2.size(); i++){
            
            while(!st.empty() && nums2[i] > st.top()) {
                int val = st.top();
                st.pop();
                if(mp.find(val) != mp.end()) {
                    res[mp[val]] = nums2[i];
                }
            }

            st.push(nums2[i]);
        }

        return res;
    }
};