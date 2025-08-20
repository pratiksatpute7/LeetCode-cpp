class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //make nums1 as the smaller array as we want to search in smaller arrya
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size(), len2 = nums2.size();
        int low = 0;
        int high = len1;


        while(low <= high) {

            // mid1 and mid2 are number of elemets taken from the respected array
            int mid1 = (low + high) / 2;
            int mid2 = (len1 + len2 + 1) / 2 - mid1;

            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int r1 = mid1 == len1 ? INT_MAX : nums1[mid1];

            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int r2 = mid2 == len2 ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if ((len1 + len2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};