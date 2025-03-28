class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(buy > prices[i]) {
                // there is no profit if the current price is less than buy
                buy = prices[i];
            } else {
                // book profit and set buy to current value
                // if we are not booking profit the next day that means we never bought it or sold it immedietly
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }

        return profit;
    }

//     int maxProfit(vector<int>& prices) {
//     int profit = 0;
//     for (int i = 1; i < prices.size(); i++) {
//         if (prices[i] > prices[i - 1]) {
//             profit += prices[i] - prices[i - 1];
//         }
//     }
//     return profit;
// }
};