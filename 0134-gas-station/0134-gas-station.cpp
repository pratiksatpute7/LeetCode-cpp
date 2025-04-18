class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currentTank = 0;
        int start = 0;
        for(int i = 0; i < cost.size(); i++) {
            int gain = gas[i] - cost[i];
            totalTank += gain;
            currentTank += gain;

            if(currentTank < 0) {
                start = i + 1;
                currentTank = 0;
            }
        }

        return totalTank < 0 ? -1 : start;
    }
};