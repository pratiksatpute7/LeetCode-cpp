class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> count;
        vector<int> result;

        for(char c : s) {
            count[c]++;
        }

        set<char> currentChars;
        int start = 0;
        int i = 0;
        while(i < s.size()) {
            count[s[i]]--;
            currentChars.insert(s[i]);
            bool part = true;
            for(char c : currentChars) {
                if(count[c] != 0) {
                    part = false;
                    break;
                }
            }

            if(part) {
                result.push_back(i - start + 1);
                currentChars.clear();
                start = i + 1;
            }

            i++;
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         unordered_map<char, int> lastIndex;
//         for (int i = 0; i < s.size(); i++) {
//             lastIndex[s[i]] = i;
//         }

//         vector<int> res;
//         int size = 0, end = 0;
//         for (int i = 0; i < s.size(); i++) {
//             size++;
//             end = max(end, lastIndex[s[i]]);

//             if (i == end) {
//                 res.push_back(size);
//                 size = 0;
//             }
//         }
//         return res;
//     }
// };