class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mp;
        
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        for(int j = 0; j < t.size(); j++) {
            if(mp.find(t[j]) == mp.end() || mp[t[j]] == 0) {
                return false;
            } else {
                mp[t[j]]--;
            }
        }

        return true;
    }
};