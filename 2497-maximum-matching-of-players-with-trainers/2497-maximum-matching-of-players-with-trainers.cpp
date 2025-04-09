class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p1 = 0;
        int p2 = 0;
        int match = 0;

        int idx = 0;

        while(p1 < players.size() && p2 < trainers.size()) {
            if(players[p1] <= trainers[p2]) {
                match++;
                p1++;
            }

            p2++;
        }

        return match;
    }
};