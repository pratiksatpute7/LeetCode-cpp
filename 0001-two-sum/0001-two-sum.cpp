class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ans;
        // int n = nums.size(), l = 0, r = n - 1;
        // int temp[n];
        // for(int i=0;i<nums.size();i++){
        //    temp[i]=nums[i];
        // }
        // sort(nums.begin(), nums.end());

        // while(l < r)
        // {
        //     int sum = nums[l] + nums[r];
        //     if(sum == target) {
        //         break;
        //     }

        //     if(sum > target) {
        //         r--;
        //     } else {
        //         l++;
        //     }
        // }

        // for(int i = 0; i < n; i++){
        //     if(nums[l] == temp[i]){
        //         ans.push_back(i);
        //     }
        //     else if(nums[r]==temp[i]){
        //         ans.push_back(i);
        //     }
        // }


        // return ans;


        // using hash set
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(mp.count(complement)) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};