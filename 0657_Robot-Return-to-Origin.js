/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

Example 1:
Input: "UD"
Output: true 
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
 
Example 2:
Input: "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
*/

// GentleSpoon me@gentlespoon.com
// Leetcode    Q657
// Start       2019-2-20 16:40:18
// Finish      2019-2-20 16:42:19

/*
Runtime: 80 ms, faster than 55.36% of JavaScript online submissions for Robot Return to Origin.
Memory Usage: 36.1 MB, less than 68.14% of JavaScript online submissions for Robot Return to Origin.
*/

/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    var c = {
        x: 0,
        y: 0
    };
    
    for (var m of moves) {
        switch (m) {
            case 'U': c.y++; break;
            case 'D': c.y--; break;
            case 'L': c.x--; break;
            case 'R': c.x++; break;
            default: throw '?';
        }
    }
    return (!c.x && !c.y);
};
