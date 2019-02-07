/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */



// GentleSpoon me@gentlespoon.com
// Leetcode    Q448
// Start       2018-01-03-1-56-19
// Finish      2018-01-03-1-58-26


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> exist;
        for (int i : nums) {
            exist.insert(i);
        }
        vector<int> dne;
        for (int i=1; i<=nums.size(); i++) {
            if (!exist.count(i)) {
                dne.push_back(i);
            }
        }
        return dne;
    }
};