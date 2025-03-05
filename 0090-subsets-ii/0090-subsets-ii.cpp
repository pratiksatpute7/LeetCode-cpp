// backtracking take not take 
class Solution {
private:
    void createSubSet(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, int n, int index) {
        if(index == n) {
            result.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        createSubSet(nums, ds, result, n, index + 1);
        ds.pop_back();

        while(index + 1 < n && nums[index + 1] == nums[index]) {
            index +=  1;
        }

        createSubSet(nums, ds, result, n, index + 1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> ds;

        createSubSet(nums, ds, result, nums.size(), 0);

        return result;



    }
};

// Back Tracking 
// class Solution {
// private:
//     void createSubSet(vector<int>& nums, vector<int>& ds, vector<vector<int>>& result, int index) {
//         // here we add what we have
//         result.push_back(ds);  


//         // take the current index push in in ds, and skip index if previous index has the same value as current index
//         for (int i = index; i < nums.size(); i++) {
//             if (i > index && nums[i] == nums[i - 1]) continue;  

//             ds.push_back(nums[i]);  
//             createSubSet(nums, ds, result, i + 1);  
//             ds.pop_back();  
//         }
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         vector<vector<int>> result;
//         vector<int> ds;

//         createSubSet(nums, ds, result, 0);

//         return result;



//     }
// };