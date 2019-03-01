// github.com/gentlespoon
// 0007 - Easy - Reverse Integer
// Start       2019-02-20-13-06-01
// Finish      2019-02-20-13-12-16
// Runtime: 92 ms, faster than 55.78% of JavaScript online submissions for Reverse Integer.
// Memory Usage: 35.8 MB, less than 70.19% of JavaScript online submissions for Reverse Integer.

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/



/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var max=2147483647; // 2^31 -1
    var ret=0, negative=0;
    if (x<0) { negative = 1; x = -x; }
    while(x>0) {
        ret = ret * 10 + x % 10;
        x = parseInt(x/10);
        if (ret > max) { return 0; }
    }
    return negative ? -ret : ret;
};
