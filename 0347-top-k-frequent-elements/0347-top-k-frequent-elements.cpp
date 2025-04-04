class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        vector<int> result;

        for(int num : nums) {
            freq[num]++;
        }

        for(auto num: freq) {
            buckets[num.second].push_back(num.first);
        }

        for (int i = n; i > 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};