# github.com/gentlespoon
# 0001 - Easy - Two Sum
# Start       2020-06-01-11-24-18
# Finish      2020-06-01-11-37-16

# Runtime: 48 ms, faster than 79.68% of Python3 online submissions for Two Sum.
# Memory Usage: 15.2 MB, less than 5.11% of Python3 online submissions for Two Sum.



# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:
# Given nums = [2, 7, 11, 15], target = 9,
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for i, num in enumerate(nums):
            if target - num in hash_table:
                return ([hash_table[target - num], i])
                break
            hash_table[num] = i
        return ([])