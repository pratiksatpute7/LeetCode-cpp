class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1; i < words.size(); i++) {
            string word1 = words[i];
            string word2 = words[i - 1];
            sort(word1.begin(), word1.end());
            sort(word2.begin(), word2.end());

            if(word1 == word2) {
                words.erase(words.begin() + i);
                i--;
            }

        }
        return words;
    }
};