class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long count = 0;
        long long pair = 0;
        int left = 0;
        int right = 0;

        for(int right = 0; right < nums.size(); right ++){
            pair += mp[nums[right]];
            mp[nums[right]] ++;

            while(pair >= k && left < right) {
                count += nums.size() - right;

                mp[nums[left]]--;
                pair -= mp[nums[left]];
                left++;
            }
        }
        return count;
    }
};