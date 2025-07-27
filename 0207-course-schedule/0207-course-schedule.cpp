// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph (numCourses);

//         for(auto preq: prerequisites) {
//             int course = preq[0];
//             int prereq = preq[1];
//             graph[prereq].push_back(course);
//         }

//         vector<int> visited(numCourses, 0);
//           // Step 3: Perform DFS on each course
//         for (int course = 0; course < numCourses; course++) {
//             if(visited[course] == 0) {
//                 if (!dfs(course, graph, visited)) {
//                     return false;
//                 }
//             }
//         }

//         return true;  // No cycles
//     }

//     bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
//         if (visited[course] == 1) return false;  // Cycle detected
//         if (visited[course] == 2) return true;   // Already processed

//         visited[course] = 1;  // Mark as visiting

//         for (int neighbor : graph[course]) {
//             if (!dfs(neighbor, graph, visited)) {
//                 return false; 
//             }
//         }

//         visited[course] = 2;
//         return true;
//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build graph and compute in-degrees
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // Queue of all nodes with inDegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visitedCount = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visitedCount == numCourses;
    }
};
