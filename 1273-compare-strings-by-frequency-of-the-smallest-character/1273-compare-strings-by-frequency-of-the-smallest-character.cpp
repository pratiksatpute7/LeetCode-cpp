class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queriesFreq;
        vector<int> wordsFreq;
        vector<int> result;
        for(string query : queries) {
            queriesFreq.push_back(f(query));
        }
        for(string word : words) {
            wordsFreq.push_back(f(word));
        }
        sort(wordsFreq.begin(), wordsFreq.end());

        for(auto queryFreq : queriesFreq) {
            int idx = upperBound(wordsFreq, queryFreq);
            result.push_back(wordsFreq.size() - idx);
        }
        return result;
    }

    int f(string s) {
        char smallest = 'z';
        int freq = 0;
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                freq = 1;
            } else if (c == smallest) {
                freq++;
            }
        }
        return freq;
    }

    int upperBound(vector<int>& wordsFreq, int queryFreq) {
        int start = 0;
        int end = wordsFreq.size();
        while (start < end) {
            int mid = start + (end - start) / 2;

            if (wordsFreq[mid] <= queryFreq) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }
};