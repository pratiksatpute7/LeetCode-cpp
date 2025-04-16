class Solution {
public:
    priority_queue<pair<int, vector<int>>> maxHeap;
    vector<vector<int>> result;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y;

            maxHeap.push({dist, point});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }

        }

        while(!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};