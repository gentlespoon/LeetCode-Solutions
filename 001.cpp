/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

// GentleSpoon me@gentlespoon.com
// Leetcode    Q1
// Start       2017-12-25-13-24-18
// Finish      2017-12-25-13-37-16


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        int sz = nums.size();
        int comp;
        for (int i=0; i<sz; i++) {
            comp = target - nums[i];
            auto index = numbers.find(comp);
            if (index!=numbers.end()) {
                return {i, index->second};
            }
            numbers[nums[i]] = i;
        }
    }
};