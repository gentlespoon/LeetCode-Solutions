/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
 */




// GentleSpoon me@gentlespoon.com
// Leetcode    Q224
// Start       2018-01-02-23-58-38
// Finish      2018-01-03-00-04-48


class Solution {
public:
    
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int result = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                result += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    result = ops.top() * result + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        result += sign * num;
        return result;
    }
};