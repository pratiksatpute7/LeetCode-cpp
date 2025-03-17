class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);

        return res;
    }

    void backtrack(int index, string combination, string& digits) {
        if(combination.size() == digits.size()) {
            res.push_back(combination);
            return;
        }
        

        string digitToString = digitToChar[digits[index] - '0'];

        for(char ch : digitToString) {
            backtrack(index + 1, combination + ch, digits);
        }
    }
};