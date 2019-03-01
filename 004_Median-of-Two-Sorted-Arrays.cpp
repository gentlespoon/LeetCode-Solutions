/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/


// github.com/gentlespoon
// Q494
// 2019-02-28-08-46-24
// 2019-02-28-08-52-19


/*
Runtime: 40 ms, faster than 97.04% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 21.3 MB, less than 86.51% of C++ online submissions for Median of Two Sorted Arrays.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1s = nums1.size();
        int n2s = nums2.size();

        if (n1s > n2s) return findMedianSortedArrays(nums2, nums1);

        int k = (n1s + n2s + 1) /2;

        int l = 0;
        int r = n1s;

        while(l<r) {
            int m1 = l+(r-l) /2;
            int m2 = k-m1;
            if (nums1[m1] < nums2[m2-1]) {
                l = m1+1;
            } else {
                r = m1;
            }
        }

        int m1 = l;
        int m2 = k-l;

        int c1 = max(m1>0?nums1[m1-1]:INT_MIN, m2>0?nums2[m2-1]:INT_MIN);

        // odd
        if ((n1s+n2s)%2) return c1;

        // even
        int c2 = min(m1<n1s?nums1[m1]:INT_MAX, m2<n2s?nums2[m2]:INT_MAX);
        return (c1+c2) /2.0;
    }
};
