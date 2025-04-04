class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> prefix;
        vector<int> freq (A.size() + 1, 0);
        int common = 0;
        
        for(int i = 0; i < A.size(); i++) {
            if(++freq[A[i]] == 2) common++;
            if(++freq[B[i]] ==2) common ++;
            prefix.push_back(common);
        }


        return prefix;
    }
};