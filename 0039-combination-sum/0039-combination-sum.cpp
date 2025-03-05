class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        subSet(candidates, ds, result, target, 0);

        return result;
    }
// void subSet(vector<int>& candidates, vector<int>& ds, vector<vector<int>>& result, int target, int index) {
//         if(target == 0) {
//             result.push_back(ds);
//             return;
//         }

//         if (target < 0 || index >= candidates.size()) {
//             return;
//         }

//         ds.push_back(candidates[index]);
//         subSet(candidates, ds, result, target - candidates[index], index);

//         ds.pop_back();

//         subSet(candidates, ds, result, target, index + 1);

//     }
    void subSet(vector<int>& candidates, vector<int>& ds, vector<vector<int>>& result, int target, int index) {
        if(target == 0) {
            result.push_back(ds);
            return;
        }

        if (target < 0 || index >= candidates.size()) {
            return;
        }

        ds.push_back(candidates[index]);
        subSet(candidates, ds, result, target - candidates[index], index);

        ds.pop_back();

        subSet(candidates, ds, result, target, index + 1);

    }
};