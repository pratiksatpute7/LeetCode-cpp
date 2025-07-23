class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> result;

        for(int i = 0; i < size; i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            groups[word].push_back(strs[i]);
        }

        for(auto item: groups) {
            result.push_back(item.second);
        }
        return result;
    }
};