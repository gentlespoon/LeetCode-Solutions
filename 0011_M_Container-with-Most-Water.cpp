// github.com/gentlespoon
// 0011 - Medium - Container with Most Water
// 2019-03-12-21-08-58
// 2019-03-12-21-16-43
// Runtime: 20 ms, faster than 98.58% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 81.92% of C++ online submissions for Container With Most Water.



/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

8|   .         .
7|   |---------|---.
6|   | .       |   |
5|   | |   .   |   |
4|   | |   | . |   |
3|   | |   | | | . |
2|   | | . | | | | |
1| . | | | | | | | |
0---------------------
   1 2 3 4 5 6 7 8 9

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/



class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0, r = height.size()-1;
        while(l<r) {
            area = max(area, min(height[l], height[r])*(r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return area;
    }
};