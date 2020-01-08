// github.com/gentlespoon
// 0794 - Medium - Valid Tic-Tac-Toe State
// Start       2020-01-08T02:24:20-07:00
// Finish      2020-01-08T02:51:50-07:00

// Runtime: 80 ms, faster than 90.48% of C# online submissions for Valid Tic-Tac-Toe State.
// Memory Usage: 24.1 MB, less than 100.00% of C# online submissions for Valid Tic-Tac-Toe State.

/*
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
*/

public class Solution {
    private int[][] win = new int[][]
    {
        new int[] {0, 1, 2}, // ```
        new int[] {3, 4, 5}, // ---
        new int[] {6, 7, 8}, // ...
        new int[] {0, 3, 6}, // 1
        new int[] {1, 4, 7}, //  1
        new int[] {2, 5, 8}, //   1
        new int[] {0, 4, 8}, // `-.
        new int[] {2, 4, 6}  // .-`
    };

    private bool checkWinner(char[] board, char player)
    {
        for (int i = 0; i < 8; i++)
        {
            if (board[win[i][0]] == player &&
                board[win[i][1]] == player &&
                board[win[i][2]] == player)
            {
                return true;
            }
        }
        return false;
    }

    public bool ValidTicTacToe(string[] board)
    {
        int x = 0, o = 0, s = 0;
        char[] b = new char[9];
        int i = 0;
        foreach (var row in board)
        {
            foreach(var grid in row)
            {
                b[i] = grid;
                i++;
                switch (grid)
                {
                    case 'X':
                        x++;
                        break;
                    case 'O':
                        o++;
                        break;
                    default:
                        s++;
                        break;
                }
            }
        }

        // check for counts
        if (x != o && x != o+1)
        {
            return false;
        }

        bool isOwin = checkWinner(b, 'O');
        bool isXwin = checkWinner(b, 'X');
        
        // Check if 'O' is winner 
        if (isOwin) {
            return isXwin ? false : (x==o);
        }

        // If 'X' wins, then count of X must be greater 
        if (isXwin && x != o + 1) {
            return false;
        }
        
        return true;
    }
}
