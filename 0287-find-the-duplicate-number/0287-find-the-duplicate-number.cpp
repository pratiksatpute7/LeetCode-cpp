class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0], hare = nums[0];

        while(true){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            
            // will meet where the cycle starts
            if(tortoise == hare) {
                break;
            }
        }

        tortoise = nums[0];
        // will give the duplicate number 
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};