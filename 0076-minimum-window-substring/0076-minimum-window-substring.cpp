class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCount;
        unordered_map<char, int> sCount;
        int minLen = INT_MAX;
        int start = 0;
        int formed = 0;
        int left = 0;
        for(char ch : t) {
            tCount[ch]++;
        }
        int matchedLen = tCount.size();

        for(int right = 0; right < s.size(); right++) {
            sCount[s[right]]++;
            
            if(tCount.count(s[right]) && tCount[s[right]] == sCount[s[right]]) {
                formed++;
            }

            while(left <= right && formed == matchedLen) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                if(tCount.find(s[left]) != tCount.end()) {
                    sCount[s[left]]--;
                    if(tCount[s[left]] > sCount[s[left]]) {
                        formed--;
                    }
                }
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};