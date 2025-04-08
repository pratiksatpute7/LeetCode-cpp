class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int size = dist.size();
        int speed = -1;
        int start = 1;
        int end = INT_MAX;

        while(start < end) {
            int currSpeed = start + (end - start) / 2;
            double time = 0.0;
            for (int i = 0; i < size; i++) {
                if (i != size - 1)
                    time += ceil((double)dist[i] / currSpeed);
                else
                    time += (double)dist[i] / currSpeed;
            }
            if(time <= hour) {
                speed = currSpeed;
                end = currSpeed;
            } else {
                start = currSpeed + 1;
            }
        }


        return speed;
    }
};