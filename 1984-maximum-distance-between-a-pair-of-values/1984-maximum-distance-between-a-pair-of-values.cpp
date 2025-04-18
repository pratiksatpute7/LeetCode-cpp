class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int maxDist = 0;

        for(int i = 0; i < len1; i++) {
            int start = i + 1;
            int end = len2 - 1;
            int best = 0;

            while(start <= end) {
                int mid = start + (end - start) / 2;

                if(nums2[mid] >= nums1[i]) {
                    best = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            if (best >= i) {
                maxDist = max(maxDist, best - i);
            }
        }


        return maxDist;
    }
};