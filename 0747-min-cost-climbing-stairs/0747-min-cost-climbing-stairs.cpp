class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // unordered_map<int, int> dp;
        // return min(findCost(0, cost, dp), findCost(1, cost, dp));
        int n = cost.size();
        int prev = 0, prev2 = 0;

        for (int i = 2; i <= n; i++) {
            int curr = min(prev + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev;
            prev = curr;
        }

        return prev;

    }

    int findCost(int index, vector<int>& cost, unordered_map<int, int>& dp){
        if(dp.find(index) != dp.end()) {
           return dp[index];
        }

        if(index >= cost.size()) {
            return 0;
        }

        int one = cost[index] + findCost(index + 1, cost, dp);

        int two = cost[index] + findCost(index + 2, cost, dp);

        if(dp.find(index) == dp.end()) {
            dp[index] = min(one, two);
        }

        return min(one, two);
    }
};