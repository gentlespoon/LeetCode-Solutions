/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
 */


// GentleSpoon me@gentlespoon.com
// Leetcode    Q463
// Start       2018-01-03-8-01-30
// Finish      2018-01-03-8-07-34

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[row].size(); col++) {
                if (grid[row][col]) {               
                    // cout << "["<<row<<"]["<<col<<"] ";
                    // check top edge
                    if (!row) {
                        // on the first row, no need to check top
                        p++;
                    } else {
                        if (!grid[row-1][col]) {
                            p++;
                        }
                    }
                    // cout << "t";
                    // check right edge
                    if (col==grid[row].size()-1) {
                        // on the right most, no need to check right
                        p++;
                    } else {
                        if (!grid[row][col+1]) {
                            p++;
                        }
                    }
                    // cout << "r";
                    // check bottom edge
                    if (row==grid.size()-1) {
                        // on the bottom most, no need to ccheck bottom
                        p++;
                    } else {
                        if (!grid[row+1][col]) {
                            p++;
                        }
                    }
                    // cout << "b";
                    // check left edge
                    if (!col) {
                        // on the first col, no need to check left
                        p++;
                    } else {
                        if (!grid[row][col-1]) {
                            p++;
                        }
                    }
                    // cout << "l";
                    // cout << p << endl;
                }
            }
        }
        return p;
    }
};