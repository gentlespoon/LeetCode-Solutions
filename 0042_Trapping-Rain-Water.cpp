/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

 */

// GentleSpoon me@gentlespoon.com
// Leetcode    Q42
// Start       2018-01-03-0-31-30
// Finish      2018-01-03-1-18-36


class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size<=2) { return 0; }
        
        
        int max = 0;
        vector<int> h_l(size);
        for (int i=0; i<size; i++) {
            if (height[i] > max) {
                max = height[i];
            }
            h_l[i] = max;
        }
        
        max = 0;
        vector<int> h_r(size);
        for (int i=size-1; i>=0; i--) {
            if (height[i] > max) {
                max = height[i];
            }
            h_r[i] = max;
        }
        
        
        // for (int i : h_l) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (int i : h_r) {
        //     cout << i << " ";
        // }
        // cout << endl;
        
        int result = 0;
        int currentGrid = 0;
        for (int i=0; i<size; i++) {
            currentGrid = min(h_l[i], h_r[i]) - height[i];
            // cout << currentGrid << " ";
            result += currentGrid;
        }
        
        return result;
    }
};