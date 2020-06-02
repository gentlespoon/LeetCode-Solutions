/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */


// GentleSpoon me@gentlespoon.com
// Leetcode    Q20
// Start       2019-02-18-15-38-42
// Finish      2019-02-18-15-42-11



/*
Runtime: 68 ms, faster than 47.20% of JavaScript online submissions for Valid Parentheses.
Memory Usage: 34 MB, less than 100.00% of JavaScript online submissions for Valid Parentheses.
*/


/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (!s.length) return true;
    else if (s.length%2) return false;
    var stack = [], a, b;
    for (a of s) {
        if ('{[('.indexOf(a) >= 0) stack.push(a);
        else {
            b = stack.pop();
            switch (a) {
                case ')': if (b!=='(') return false; break;
                case ']': if (b!=='[') return false; break;
                case '}': if (b!=='{') return false; break;
                default: return false;
            }
        }        
    }
    if (stack.length) return false;
    return true;
}
