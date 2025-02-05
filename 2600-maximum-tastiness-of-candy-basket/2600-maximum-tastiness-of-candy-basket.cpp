class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int min = price.front();
        int max = price.back();

        int tastiness = max - min;
        int start = 0; 
        int end = tastiness;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isValid(mid, price, k)) {
                tastiness = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return tastiness;
        
    }

    bool isValid(int tastiness, vector<int>& price, int k) {
        int lastCandyPrice = price[0];
        int count = 1; // First candy is always chosen

//         We iterate through the sorted array of candy prices.
// We pick the first candy (always).
// For each next candy, we check:
// Can it be selected?
// ➝ If the price difference between the last selected candy and the current candy is at least x, we pick it.
// If we select k candies, we return true (valid tastiness).
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - lastCandyPrice >= tastiness) {
                count++;
                lastCandyPrice = price[i]; // Update last selected candy price
                if (count == k) return true; // If k candies are taken, return true
            }
        }
        return false;
    }
};