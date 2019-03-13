// github.com/gentlespoon
// 0151 - Medium - Reverse Words in a String
// 2019-03-12-22-14-52
// 2019-03-12-22-17-00
// Runtime: 56 ms, faster than 88.29% of JavaScript online submissions for Reverse Words in a String.
// Memory Usage: 34.3 MB, less than 37.76% of JavaScript online submissions for Reverse Words in a String.


/*
Given an input string, reverse the string word by word.



Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  var ret = '';
  for (var i of s.split(' ').reverse()) {
      if (i==='') continue;
      if (ret) ret += ' ';
      ret += i;
  }
  return ret;
};