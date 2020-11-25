// github.com/gentlespoon
// 0409 - Easy - Longest Palindrome
// 2020-11-25T10:03:11-07:00
// 2020-11-25T10:24:14-07:00
// Runtime: 84 ms, faster than 73.64% of JavaScript online submissions for Longest Palindrome.
// Memory Usage: 40.5 MB, less than 29.20% of JavaScript online submissions for Longest Palindrome.

/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Example 3:

Input: s = "bb"
Output: 2
 

Constraints:

1 <= s.length <= 2000
s consits of lower-case and/or upper-case English letters only.

*/

/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let map = {};
    for (let c of s) {
        map[c] = map[c] ? map[c]+1 : 1;
    }
    let length = 0;
    let single = 0;
    for (let c of Object.keys(map)) {
        if (map[c]%2) {
            single = 1;
        }
        length += Math.floor(map[c]/2) * 2;
    }
    length += single;
    return length;
};