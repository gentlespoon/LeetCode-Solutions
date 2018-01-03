/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
 */



// GentleSpoon me@gentlespoon.com
// Leetcode    Q200
// Start       2018-01-03-8-25-26
// Finish      2018-01-03-8-48-27


class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size();
    int col = grid[0].size();
    int islands = 0;
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (grid[y][x]=='1') { islands++; }
        dfs(grid, x, y, row, col);
      }
    }
    return islands;
  }
 
  void dfs(vector<vector<char>>&grid, int x, int y, int row, int col) {
    // cout << x << " " << y << " " << row << " " << col << endl; 
    if (x<0 || y<0 || x>=col || y>=row || grid[y][x]=='0') { return; }
    grid[y][x] = '0';
    dfs(grid, x+1, y, row, col);
    dfs(grid, x-1, y, row, col);
    dfs(grid, x, y+1, row, col);
    dfs(grid, x, y-1, row, col);
  }
};
