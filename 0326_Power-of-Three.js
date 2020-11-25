/*
Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true

Example 2:
Input: 0
Output: false

Example 3:
Input: 9
Output: true

Example 4:
Input: 45
Output: false

Follow up:
Could you do it without using any loop / recursion?
*/

// Follow up: I could not. I give up.


// GentleSpoon me@gentlespoon.com
// Leetcode    Q326
// Start       2019-2-20 17:02:37
// Finish      2019-2-20 17:06:16

/*
Runtime: 344 ms, faster than 48.31% of JavaScript online submissions for Power of Three.
Memory Usage: 48.2 MB, less than 30.30% of JavaScript online submissions for Power of Three.
*/

/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    if (n < 1) return false;
    while (n > 1) {
        if (n % 3 !== 0) return false;
        n /= 3;
    }
    return true;
}
