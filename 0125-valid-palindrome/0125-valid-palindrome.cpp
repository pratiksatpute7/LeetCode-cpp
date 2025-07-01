class Solution {
public:
    bool isPalindrome(string s) {
        string f;

        for(char c : s) {
            if(isalnum(c)) {
                f += tolower(c);
            }
        }

        int left = 0; 
        int right = f.size() - 1;

        while (left < right) {
            if(f[left] == f[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;

    }
};