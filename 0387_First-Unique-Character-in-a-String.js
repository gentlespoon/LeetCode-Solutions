/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

// GentleSpoon me@gentlespoon.com
// Leetcode    Q387
// Start       2019-2-20 16:48:42
// Finish      2019-2-20 17:00:10


/*
Runtime: 100 ms, faster than 72.88% of JavaScript online submissions for First Unique Character in a String.
Memory Usage: 38 MB, less than 69.59% of JavaScript online submissions for First Unique Character in a String.
*/

/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    var u = new Map();
    var d = new Map();
    for (var i of s) {
        if (!d.has(i)) {
            if (!u.has(i))
                u.set(i, 0);
            else {
                u.delete(i);
                d.set(i, 0);
            }
        }
    }
    return s.indexOf(u.keys().next().value);
};
