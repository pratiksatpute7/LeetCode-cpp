class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // unordered_map<int, int> dp;
        // return min(findCost(0, cost, dp), findCost(1, cost, dp));

        int n = cost.size();
        int pre1 = 0;
        int pre2 = 0;

        for(int i = n -1; i >= 0; i--) {
            int curr = cost[i] + min(pre1, pre2);
            pre2 = pre1;
            pre1 = curr;
        }

        return min(pre1, pre2);
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