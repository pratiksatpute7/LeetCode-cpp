class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = INT_MIN;
        while(left <= right) {
            int h = min(height[left], height[right]);
            int l = right - left;
            area = max(l * h, area);

            if(height[left] < height[right]) {
                left = left + 1;
            } else {
                right = right - 1;
            }
        }

        return area;
    }
};