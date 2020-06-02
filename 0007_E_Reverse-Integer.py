# github.com/gentlespoon
# 0007 - Easy - Reverse Integer
# Start       2020-06-01-12-27-01
# Finish      2019-06-01-12-39-43

# Runtime: 20 ms, faster than 75.24% of Python online submissions for Reverse Integer.
# Memory Usage: 12.9 MB, less than 5.38% of Python online submissions for Reverse Integer.

# Given a 32-bit signed integer, reverse digits of an integer.

# Example 1:
# Input: 123
# Output: 321

# Example 2:
# Input: -123
# Output: -321

# Example 3:
# Input: 120
# Output: 21

# Note:
# Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        # for input x outside the 32-bit signed integer range: [−2^31,  2^31 − 1] return 0
        if x < -2147483648 or x > 2147483647:
            return 0
        
        isPositive = 1 if x > 0 else -1
        x = abs(x)
        
        result = 0
        while x > 0:
            result = result * 10 + x % 10
            x = x / 10
        result *= isPositive

        # for output result outside 32-bit signed integer range return 0    
        return result if (result > -2147483648 and result < 2147483647) else 0


    


    