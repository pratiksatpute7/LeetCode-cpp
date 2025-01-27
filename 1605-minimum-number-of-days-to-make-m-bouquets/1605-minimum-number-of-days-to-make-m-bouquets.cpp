class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //sorting was wrong as this requires consecutive flowers to built a bouquts
        // sort(bloomDay.begin(), bloomDay.end());

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end =*max_element(bloomDay.begin(), bloomDay.end());
        long long numFlower = (long long)m * k; 

        int res = -1;

        if(bloomDay.size() < numFlower){
            return res;
        }

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isValid(bloomDay, mid, m, k)){
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return res;
    }
    
    bool isValid(vector<int>& bloomDay, int mid, int m, int k){
        int numFlower = 0;
        int numOfBouquets = 0;

        // we iterater over the array and check if we have enough continuous flower to make a bouquets
        for(int bloom: bloomDay) {
            //if curr bloom is <= mid means flower is ready
            if(bloom <= mid) {
                //count the flower
                numFlower ++;

                // check if we have enought continuous flower to make bouquet 
                // if yes increment numOfBouquets and reset numFlower
                if(numFlower == k) {
                    numOfBouquets ++;
                    numFlower = 0;
                }
            } 
            // If the above condition is not meant means that there are no enough continous flower 
            // resent the numFlower counter 
            else {
                numFlower = 0;
            }

            if(m == numOfBouquets) {
                return true;
            }
        }
        return false;
    }
};