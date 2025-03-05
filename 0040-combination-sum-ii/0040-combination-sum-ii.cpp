class Solution {
private:
    void subset(vector<int>& candidates, vector<vector<int>>& result, vector<int>& ds, int target, int sum, int index) {
        if(target == sum) {
            result.push_back(ds);
            return;
        }

        for(int j = index; j < candidates.size(); j++) {
            if(j > index && candidates[j] == candidates[j - 1]) {
                continue;
            }
            if(sum + candidates[j] > target) {
                return;
            }

            ds.push_back(candidates[j]);
            subset(candidates, result, ds, target, sum + candidates[j], j + 1);

            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        int sum = 0;
        sort(candidates.begin(), candidates.end());

        subset(candidates, result, ds, target, sum, 0);

        return result;
    }
};