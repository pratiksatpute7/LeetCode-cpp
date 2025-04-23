class Solution {
public:
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto preq : prerequisites) {
            int course = preq[0];
            int prereq = preq[1];
            graph[prereq].push_back(course);
        }

        vector<int> visited(numCourses, 0);
        for(int course = 0; course < numCourses; course++) {
             if (visited[course] == 0) {
                if (!dfs(course, graph, visited)) {
                    return {};
                }
            }
        }

        reverse(result.begin(), result.end());  

        return result;


    }

    bool dfs(int node, vector<vector<int>>& prerequisites, vector<int>& visited){
        // Cycle detected
        if(visited[node] == 1) {
            return false;
        }

        // Already visited
        if(visited[node] == 2) {
            return true;
        }

        visited[node] = 1;

        for(int neighbour : prerequisites[node]) {
            if(!dfs(neighbour, prerequisites, visited)) {
                return false;
            }
        }

        visited[node] = 2;
        result.push_back(node);

        return true;
    }
};