# github.com/gentlespoon
# 0020 - Easy - Valid Parentheses
# Start       2020-06-01-13-24-18
# Finish      2020-06-01-13-37-16

# Runtime: 28 ms, faster than 75.13% of Python3 online submissions for Valid Parentheses.
# Memory Usage: 14 MB, less than 5.22% of Python3 online submissions for Valid


# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution:
    def isValid(self, s: str) -> bool:
        
        stack = []
        for i in list(s):
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            elif i == ')':
                if len(stack) == 0 or stack.pop() != '(':
                    return False
            elif i == ']':
                if len(stack) == 0 or stack.pop() != '[':
                    return False
            elif i == '}':
                if len(stack) == 0 or stack.pop() != '{':
                    return False
        return 0 == len(stack)
