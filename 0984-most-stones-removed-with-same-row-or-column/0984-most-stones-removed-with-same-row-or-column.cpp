class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int> visited;
        int components = 0;

        for(int i = 0; i < stones.size(); i++) {
            if(!visited.count(i)) {
                components++;
                bfs(i, stones, visited);
            }
        }

        return stones.size() - components;
    }

    void bfs(int start, vector<vector<int>>& stones, unordered_set<int>& visited) {
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int next = 0; next < stones.size(); next++) {
                if(!visited.count(next)) {
                    if(stones[curr][0] == stones[next][0] || stones[curr][1] == stones[next][1]) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
    }
};