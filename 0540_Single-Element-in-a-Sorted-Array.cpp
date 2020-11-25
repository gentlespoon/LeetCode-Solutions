/*

Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.

*/

// GentleSpoon me@gentlespoon.com
// Leetcode    Q540
// Start       2017-12-16-14-27-52
// Finish      

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            int n = m % 2 == 0 ? m + 1 : m - 1;
            if (nums[m] == nums[n])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};