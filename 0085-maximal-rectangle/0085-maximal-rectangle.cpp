class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
     int maxRow = matrix.size();
        int maxCol = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(maxCol, 0);

        for(int row = 0; row < maxRow; row ++) {
            for(int col = 0; col < maxCol; col ++) {
                if(matrix[row][col] == '1') {
                    heights[col] += 1;
                } else {
                    heights[col] = 0;  // reset on '0'
                }
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); 
        int area = 0;
        stack<int> st;
        int size = heights.size();

        for(int i = 0; i < size; i++) {
            while(!st.empty() && (i == size || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;

                area = max(area, height * width);
            }

            st.push(i);
        }

        return area;
    }
};