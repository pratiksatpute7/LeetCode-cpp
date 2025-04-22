class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        map<int, int> count;

        // Step 1: Build frequency map
        for (int card : hand) {
            count[card]++;
        }

        // Step 2: Process the map from smallest to largest
        while (!count.empty()) {
            int start = count.begin()->first;  // always smallest key

            // Try to form one group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;

                if (count[curr] == 0) return false;  // group can't be formed

                count[curr]--;

                if (count[curr] == 0) {
                    count.erase(curr);  // safe to erase inside the loop
                }
            }
        }

        return true;
    }
};
