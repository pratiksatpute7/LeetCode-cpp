class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num : nums) {
            mp[num]++;
        }

            int longest = 0;

    // Step 2: For each number, check if number + 1 exists
            for (auto& [key, value] : mp) {
                if (mp.count(key + 1)) {
                    longest = max(longest, value + mp[key + 1]);
                }
            }

            return longest;


    }
};