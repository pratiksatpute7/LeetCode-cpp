class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> car;
        stack<float> fleet;
        int size = position.size();
        for(int i = 0; i < size; i++) {
            float time = (float) (target - position[i]) / speed[i];

            car.push_back({position[i], time});
        }

        sort(car.begin(), car.end());

        for(int i = 0; i < size; i++) {
            float time = car[i].second;

            // current car will take more time than previous car 
            // index 1 car will take more time than index 0 car 
            // i.e. index 0 car will catch index 1 and form a fleet 
            while(fleet.size() && time >= fleet.top()) {
                fleet.pop();
            }

            fleet.push(time);
        }

        return fleet.size();
    }
};