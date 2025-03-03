class Solution {
public:
    // recursive
    // bool isPowerOfTwo(int n) {
    //     if (n == 0) {
    //         return false;
    //     }
    //     if(n == 1) {
    //         return true;
    //     }

    //     if(n % 2 == 0) {
    //         return isPowerOfTwo(n/2);
    //     }

    //     return false;
    // }
    

    //Bit manipulation
    // bool isPowerOfTwo(int n) {
    //     if (n == 0) {
    //         return false;
    //     }
    //     if(n == 1) {
    //         return true;
    //     }

    //     if((n & 1) == 0) {
    //         return isPowerOfTwo(n/2);
    //     }

    //     return false;
    // }

    bool isPowerOfTwo(int n) {
        // in binary if a number is power of 2 only 1 bit is set
        // there we perform bitwise & with n - 1
        // in n - 1 all bits are set except the bit set in n
        // so when we perform add operation result should be equal to 0
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};