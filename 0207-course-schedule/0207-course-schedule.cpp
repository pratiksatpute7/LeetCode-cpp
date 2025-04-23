class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);

        for(auto preq: prerequisites) {
            int course = preq[0];
            int prereq = preq[1];
            graph[prereq].push_back(course);
        }

        vector<int> visited(numCourses, 0);
          // Step 3: Perform DFS on each course
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, graph, visited)) {
                return false;
            }
        }

        return true;  // No cycles
    }

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1) return false;  // Cycle detected
        if (visited[course] == 2) return true;   // Already processed

        visited[course] = 1;  // Mark as visiting

        for (int neighbor : graph[course]) {
            if (!dfs(neighbor, graph, visited)) {
                return false; 
            }
        }

        visited[course] = 2;
        return true;
    }
};