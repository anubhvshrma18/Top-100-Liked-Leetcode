#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        bool isOdd = total % 2;

        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }

        int left = 0, right = nums1.size() - 1;
        while (true) {
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1 - 2;

            int L1 = mid1 >= 0 ? nums1[mid1] : INT_MIN;
            int R1 = mid1 + 1 < nums1.size() ? nums1[mid1 + 1] : INT_MAX;
            int L2 = mid2 >= 0 ? nums2[mid2] : INT_MIN;
            int R2 = mid2 + 1 < nums2.size() ? nums2[mid2 + 1] : INT_MAX;

            if (L1 <= R2 && L2 <= R1) {
                if (isOdd) {
                    return std::min(R1, R2);
                } else {
                    return (std::max(L1, L2) + std::min(R1, R2)) / 2.0;
                }
            } else if (L1 > R2) {
                right = mid1 - 1;
            } else {
                left = mid1 + 1;
            }
        }
    }
};