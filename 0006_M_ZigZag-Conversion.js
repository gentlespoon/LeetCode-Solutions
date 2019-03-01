// github.com/gentlespoon
// 0006 - Medium - ZigZag Conversion
// Start       2019-02-07-23-01-01
// Finish      2019-02-07-23-12-16
// Runtime: 116ms, beats 52.36% of JavaScript submissions.

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/




/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1 || numRows > s.length) {
        return s;
    }
    var str = new Array(numRows).fill('');
    var row = 0;
    var down = true;
    for (var i of s) {
		str[row] += i;
        if (down) {
            if (row===numRows-1) {
                row--;
                down = false;
            } else {
                row++;
            }
        } else {
            if (row===0) {
                row++;
                down = true;
            } else {
                row--;

            }
        }
    }
    // console.log(str);
    return str.join('');
};
