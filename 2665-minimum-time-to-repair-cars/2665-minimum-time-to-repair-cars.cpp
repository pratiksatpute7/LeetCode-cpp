class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
       long long start = 1; 
       long long end = 1LL * (*min_element(ranks.begin(), ranks.end())) * 1LL * cars * cars;

        while(start < end) {
            long long mid = start + (end - start) / 2;
            long long totalCars = 0;
            for(int rank : ranks) {
                totalCars += (long long)(sqrt(mid / rank));
            }

            if(totalCars >= cars) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};