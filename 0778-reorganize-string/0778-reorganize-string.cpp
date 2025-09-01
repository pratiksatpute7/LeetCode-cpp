class Solution {
public:
    string reorganizeString(string s) {
        // make freq array
        int n = s.size();
        array<int, 26> freq{};

        for(char c : s) {
            freq[c - 'a']++;
        }

        int maxF = 0;
        int maxC = -1;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxF) {
                maxF = freq[i];
                maxC = i;
            }
        }

        // If one char occurs more than half of the string then it is impossible
        if (maxF > (n + 1) / 2) return "";

        string result(n, ' ');
        int idx = 0;

        while (freq[maxC] > 0) {
            result[idx] = char('a' + maxC);
            idx += 2;
            freq[maxC]--;
        }

         for (int c = 0; c < 26; c++) {
            while (freq[c] > 0) {
                if (idx >= n){
                   idx = 1;   // switch to odd positions 
                } 
                result[idx] = char('a' + c);
                idx += 2;
                freq[c]--;
            }
        }
        return result;
    }
};