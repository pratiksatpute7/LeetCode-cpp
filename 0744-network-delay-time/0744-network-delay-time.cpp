class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed
        vector<int> dist(n + 1, INT_MAX);

        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({k, 0});
        dist[k] = 0;

        while(!pq.empty()) {
            auto item = pq.top();
            int u = item.first;
            int d = item.second;
            pq.pop();

            if (d > dist[u]) continue;

            for(auto& [v, w] : graph[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                }
            }

        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // Unreachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;

    }
};