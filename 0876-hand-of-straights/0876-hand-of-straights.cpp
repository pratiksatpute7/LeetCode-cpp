class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        map<int, int> count;

        for (int card : hand) {
            count[card]++;
        }

        while (!count.empty()) {
            int start = count.begin()->first;  
            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;

                if (count[curr] == 0) return false;  

                count[curr]--;

                if (count[curr] == 0) {
                    count.erase(curr); 
                }
            }
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size() % groupSize != 0) return false;

//         unordered_map<int, int> count;
//         for (int num : hand) count[num]++;
        
//         for (int num : hand) {
//             int start = num;
//             while (count[start - 1] > 0) start--;
//             while (start <= num) {
//                 while (count[start] > 0) {
//                     for (int i = start; i < start + groupSize; i++) {
//                         if (count[i] == 0) return false;
//                         count[i]--;
//                     }
//                 }
//                 start++;
//             }
//         }
//         return true;
//     }
// };
