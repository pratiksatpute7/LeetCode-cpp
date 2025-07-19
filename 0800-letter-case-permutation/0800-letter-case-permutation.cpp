class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string path;
        backtrack(s, 0, path, result);
        return result;
    }

    void backtrack(const string& s, int index, string& path, vector<string>& result) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        char c = s[index];

        if (isdigit(c)) {
            path.push_back(c);
            backtrack(s, index + 1, path, result);
            path.pop_back();
        } else {
            // Lowercase
            path.push_back(tolower(c));
            backtrack(s, index + 1, path, result);
            path.pop_back();

            // Uppercase
            path.push_back(toupper(c));
            backtrack(s, index + 1, path, result);
            path.pop_back();
        }
    }
};
