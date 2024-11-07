#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            // If partitionX is 0, it means there are no elements on the left side from nums1
            // If partitionX is m, it means all elements are on the left side from nums1
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            // Same for nums2
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Check if we have found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If the total length is odd
                if ((m + n) % 2 == 1) {
                    return double(max(maxLeftX, maxLeftY));
                }
                // If the total length is even
                return (double(max(maxLeftX, maxLeftY)) + double(min(minRightX, minRightY))) / 2.0;
            } 
            // If we are too far on the right side for nums1, go left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            // If we are too far on the left side for nums1, go right
            else {
                low = partitionX + 1;
            }
        }

        // If we reach here, it means the arrays are not sorted properly
        throw invalid_argument("Input arrays are not sorted.");
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "The median is: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};

    cout << "The median is: " << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl;

    return 0;
}
