class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;

        while(right < s.size()) {
            mp[s[right]] += 1;

            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};