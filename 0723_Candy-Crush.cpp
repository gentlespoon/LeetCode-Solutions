/*
This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.

Example:
Input:
board =
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]

Output:
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
Explanation:
[Image]


Note:
The length of board will be in the range [3, 50].
The length of board[i] will be in the range [3, 50].
Each board[i][j] will initially start as an integer in the range [1, 2000].
*/



// github.com/gentlespoon
// Q723
// 2019-02-28-14-45-16
// 2019-02-28-15-53-42



/*
Runtime: 28 ms, faster than 100.00% of C++ online submissions for Candy Crush.
Memory Usage: 10.4 MB, less than 54.55% of C++ online submissions for Candy Crush.
*/

class Solution {
public:
    // recurse until stable
    // scan row by row - top to bottom
    // check only down and right direction
    // after each crush, fall the board

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int hasCrush = 0;
        if (!board.size() || !board[0].size()) return board;
        // scan board for crushable
        for (int y=0; y<board.size(); y++) {
            for (int x=0; x<board[0].size(); x++) {
                if (board[y][x]) {
                    hasCrush += crush(board, y, x);
                }
            }
        }

        fall(board);
        // printBoard(board);
        if (hasCrush) {
            return candyCrush(board);
        } else {
            return board;
        }
    }



    int crush(vector<vector<int>>& board, int y, int x) {
        // border handle
        if (y>=board.size() || x>=board[0].size()) return 0;
        int crushed = 0;
        int candyType = abs(board[y][x]);
        if (x+2 < board[0].size()) {
            // cout << "checking " << y << ",\t" << x+1 << "\t" << board[y][x+1] << "\t" << endl;
            // cout << "checking " << y << ",\t" << x+2 << "\t" << board[y][x+2] << "\t" << endl;
            if (abs(board[y][x+1]) == candyType && abs(board[y][x+2]) == candyType) {
                board[y][x+1] = board[y][x+2] = -1 * candyType;
                crushed++;
                // printBoard(board);
            }
        }
        if (y+2 < board.size()) {
            // cout << "checking " << y+1 << ",\t" << x << "\t" << board[y+1][x] << "\t" << endl;
            // cout << "checking " << y+2 << ",\t" << x << "\t" << board[y+2][x] << "\t" << endl;
            if (abs(board[y+1][x]) == candyType && abs(board[y+2][x]) == candyType) {
                board[y+1][x] = board[y+2][x] = -1 * candyType;
                crushed++;
                // printBoard(board);
            }
        }
        if (crushed) {
            board[y][x] = -1 * candyType;
        }
        return crushed;
    }


    void fall(vector<vector<int>>& board) {
        // fall col by col
        for (int x=0; x<board[0].size(); x++) {
            // check from bottom to top
            for (int y=board.size()-1; y>=0; y--) {
                if (board[y][x]<=0) {
                    // if this grid is crushed, grab the lowest candy above it
                    for (int y2=y; y2>=0; y2--) {
                        if (board[y2][x]>0) {
                            board[y][x]=board[y2][x];
                            board[y2][x]=0;
                            break;
                        }
                    }
                    // if no candy above, set to 0
                    if (board[y][x]<0) board[y][x]=0;
                }
            }
        }
    }

    void printBoard(vector<vector<int>>& board) {
        for (int y=0; y<board.size(); y++) {
            for (int x=0; x<board[0].size(); x++) {
                cout << "\t" << board[y][x];
            }
            cout << endl;
        }
    }
};
