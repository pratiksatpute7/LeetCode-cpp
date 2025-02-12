class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int ans = 0;
        for (char dir : directions) {
            // Process each car
            while (!st.empty() && st.top() == 'R' && dir == 'L') {
                ans += 2; // 'R' and 'L' collide
                st.pop();
                dir = 'S'; // Convert current car into 'S' (stationary)
            }

            while (!st.empty() && st.top() == 'R' && dir == 'S') {
                ans++; // 'R' crashes into 'S'
                st.pop();
            }

            if (!st.empty() && st.top() == 'S' && dir == 'L') {
                ans++; // 'L' crashes into 'S'
                dir = 'S';  // Convert it to 'S'
            }

            st.push(dir);
        }

        return ans;
    }
};