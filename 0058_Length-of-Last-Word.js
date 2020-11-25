/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example: 
Input: "Hello World"
Output: 5

*/

// GentleSpoon me@gentlespoon.com
// Leetcode    Q058
// Start       2019-01-18-01-13-05
// Finish      2019-01-18-01-15-52


/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var count = 0;
    var lastWordExists = 0;
    for (let i=s.length-1; i>=0; i--) {
        if (s.charAt(i) === ' ') {
            if (lastWordExists)
                break;
        } else {
            count++;
            lastWordExists=1;
        }
    }
    return count;
};
