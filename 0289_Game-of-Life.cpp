/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

// GentleSpoon <me@gentlespoon.com>
// Q289
// 2019-02-27-15-30-55
// 2019-02-27-15-42-09
  
/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Game of Life.
Memory Usage: 8.9 MB, less than 50.63% of C++ online submissions for Game of Life.
*/

    
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (!board.size() || !board[0].size()) return;
        int sizeY = board.size();
        int sizeX = board[0].size();
        for (int y = 0; y < sizeY; y++) {
            for (int x = 0; x < sizeX; x++) {
                judge(board, x, y, sizeX, sizeY);
            }    
        }
        for (int y = 0; y < sizeY; y++) {
            for (int x = 0; x < sizeX; x++) {
                board[y][x] /= 2;
            }    
        }
    }
    
    void judge(vector<vector<int>>& board, int x, int y, int sizeX, int sizeY) {
        int nab = 0;
        if (y-1>=0    && x-1>=0   ) {
            nab += board[y-1][x-1]%2;
            // cout << '7' << '=' << nab;
        }
        if (y-1>=0    && 1        ) {
            nab += board[y-1][x]%2;
            // cout << '8' << '=' << nab;
        }
        if (y-1>=0    && x+1<sizeX) {
            nab += board[y-1][x+1]%2;
            // cout << '9' << '=' << nab;
        }
        if (1         && x-1>=0   ) {
            nab += board[y][x-1]%2;
            // cout << '4' << '=' << nab;
        }
        if (1         && x+1<sizeX) {
            nab += board[y][x+1]%2;
            // cout << '6' << '=' << nab;
        }
        if (y+1<sizeY && x-1>=0   ) {
            nab += board[y+1][x-1]%2;
            // cout << '1' << '=' << nab;
        }
        if (y+1<sizeY && 1        ) {
            nab += board[y+1][x]%2;
            // cout << '2' << '=' << nab;
        }
        if (y+1<sizeY && x+1<sizeX) {
            nab += board[y+1][x+1]%2;
            // cout << '3' << '=' << nab;
        }
        // cout << '\t' << nab << endl;
        if (nab <= 1 || nab >= 4) board[y][x] = board[y][x];
        if (nab == 2) board[y][x] += board[y][x] << 1;
        if (nab == 3) board[y][x] += 2;
    }
};
