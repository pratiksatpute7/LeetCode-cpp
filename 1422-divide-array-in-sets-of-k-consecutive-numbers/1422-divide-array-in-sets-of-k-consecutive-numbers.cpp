class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        if (nums.size() % k != 0) return false;


        for(int num : nums) {
            count[num]++;
        }

        for(int num : nums) {
            int start = num;
            while(count[start - 1] > 0) {
                start--;
            }
            while (start <= num) {
                while(count[start] > 0) {
                    for(int i = start; i < start + k; i++) {
                        if (count[i] == 0) {
                            return false;
                        } 
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};