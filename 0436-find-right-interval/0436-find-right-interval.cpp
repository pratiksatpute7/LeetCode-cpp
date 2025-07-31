class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;  // {start, original_index}

        for (int i = 0; i < n; ++i) {
            starts.emplace_back(intervals[i][0], i);
        }

        // Sort based on start
        sort(starts.begin(), starts.end());

        vector<int> result;

        for (auto& interval : intervals) {
            int target = interval[1];
            int left = 0, right = n - 1;
            int idx = -1;

            // Binary search for smallest start >= end
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= target) {
                    idx = starts[mid].second;  // possible answer
                    right = mid - 1;           // try to find smaller one
                } else {
                    left = mid + 1;
                }
            }

            result.push_back(idx);
        }

        return result;
    }
};
