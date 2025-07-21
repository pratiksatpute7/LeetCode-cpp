class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxLen = 0;
        int start = 0;

        while (start < word.size()) {
            // Skip until we find 'a'
            if (word[start] != 'a') {
                start++;
                continue;
            }

            int end = start;
            int vowelIndex = 0;
            string vowels = "aeiou";

            while (end < word.size() && word[end] >= vowels[vowelIndex]) {
                if (word[end] == vowels[vowelIndex]) {
                    end++;
                } else if (vowelIndex < 4 && word[end] == vowels[vowelIndex + 1]) {
                    vowelIndex++;
                } else {
                    break;
                }
            }

            if (vowelIndex == 4) {  // all vowels seen
                maxLen = max(maxLen, end - start);
            }

            start = end;  // move to next possible start
        }

        return maxLen;
    }
};
