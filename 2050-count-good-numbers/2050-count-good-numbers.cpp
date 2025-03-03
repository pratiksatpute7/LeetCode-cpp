class Solution {
public:
    int M = 1e9+7;
    long long betterPower(long long base, long long exp, long long ans) {
        if(exp == 0) {
            return ans;
        }

        if(exp % 2 == 1) {
            return betterPower(base, exp - 1, (base * ans) % M);
        } else {
            // if even index square the base and half the exponent  
            return betterPower((base * base) % M, exp / 2, ans);
        }
    }    
    
    int countGoodNumbers(long long n) {
        // Each odd even pair index has 20 choice as 5 * 4
        long long totalWaysForPairs = betterPower(20, n/2, 1);

        //check if there were odd index if yes multiply by 5 to consider for last even index
        return (n % 2 == 1) ? (totalWaysForPairs * 5) % M : totalWaysForPairs;
    }
};