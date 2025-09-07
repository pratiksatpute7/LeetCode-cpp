// class Solution {
// public:
//     vector<int> result;
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);

//         for(auto preq : prerequisites) {
//             int course = preq[0];
//             int prereq = preq[1];
//             graph[prereq].push_back(course);
//         }

//         vector<int> visited(numCourses, 0);
//         for(int course = 0; course < numCourses; course++) {
//              if (visited[course] == 0) {
//                 if (!dfs(course, graph, visited)) {
//                     return {};
//                 }
//             }
//         }

//         reverse(result.begin(), result.end());  

//         return result;


//     }

//     bool dfs(int node, vector<vector<int>>& prerequisites, vector<int>& visited){
//         // Cycle detected
//         if(visited[node] == 1) {
//             return false;
//         }

//         // Already visited
//         if(visited[node] == 2) {
//             return true;
//         }

//         visited[node] = 1;

//         for(int neighbour : prerequisites[node]) {
//             if(!dfs(neighbour, prerequisites, visited)) {
//                 return false;
//             }
//         }

//         visited[node] = 2;
//         result.push_back(node);

//         return true;
//     }
// };

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Step 1: Build graph and in-degree array
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        // Step 2: Enqueue courses with no prerequisites
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // Step 3: Process queue (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check if all courses are taken
        if (result.size() == numCourses) {
            return result;
        } else {
            return {}; // cycle detected
        }
    }
};
