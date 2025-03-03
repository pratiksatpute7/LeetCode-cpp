class Solution {
    
public:

    string genString(int i) {
        if(i == 0) {
            return "0";
        }
        string pre = genString(i - 1);
        string invert = invertBinary(pre); // Correct bit inversion
        reverse(invert.begin(), invert.end()); // Reverse the inverted string
        return (pre + "1" + invert);
    }

    string invertBinary(string s) {
        for(char &ch : s) {
            ch = (ch == '0') ? '1' : '0'; // Flip bits manually
        }
        return s;
    }
    
    char findKthBit(int n, int k) {
        return genString(n)[k -1];
    }
};