class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> dp;
        return min(findCost(0, cost, dp), findCost(1, cost, dp));
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