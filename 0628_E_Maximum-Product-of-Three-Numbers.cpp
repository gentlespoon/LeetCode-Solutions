// github.com/gentlespoon
// 0628 - Easy - Maximum Product of Three Numbers
// 2019-03-01-23-10-06
// 2019-03-01-23-36-22
// Runtime: 48 ms, faster than 68.14% of C++ online submissions for Maximum Product of Three Numbers.
// Memory Usage: 11.2 MB, less than 89.44% of C++ online submissions for Maximum Product of Three Numbers.


/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6


Example 2:
Input: [1,2,3,4]
Output: 24

Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution_Vector {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        if (nums.size() == 3) return nums[0]*nums[1]*nums[2];

        vector<int> positive(3);
        vector<int> negative(2);

        for (int& i : nums) {
            if (!i) continue;
            if (i>0) {
                const int minI = minIndex(positive);
                if (i>positive[minI])
                    positive[minI] = i;
            } else {
                const int maxI = maxIndex(negative);
                if (i<negative[maxI])
                    negative[maxI] = i;
            }
        }

        const int neg = negative[0] * negative[1] * positive[maxIndex(positive)];
        const int pos = positive[0] * positive[1] * positive[2];
        return max(neg, pos);
    }

    int minIndex(const vector<int>& arr) {
        int minI = 0;
        int minV = INT_MAX;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]<minV) {
                minI = i;
                minV = arr[i];
            }
        }
        return minI;
    }
    int maxIndex(const vector<int>& arr) {
        int maxI = 0;
        int maxV = INT_MIN;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]>maxV) {
                maxI = i;
                maxV = arr[i];
            }
        }
        return maxI;
    }
};


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        if (nums.size() == 3) return nums[0]*nums[1]*nums[2];

        int p1, p2, p3, n1, n2;
        p1 = p2 = p3 = n1 = n2 = 0;

        for (int& i : nums) {
            if (!i) continue;
            if (i>0) {
                if (i>p3) {
                    p1 = p2;
                    p2 = p3;
                    p3 = i;
                } else
                if (i>p2) {
                    p1 = p2;
                    p2 = i;
                } else
                if (i>p1) {
                    p1 = i;
                }
            } else {
                if (i<n2) {
                    n1 = n2;
                    n2 = i;
                } else
                if (i<n1) {
                    n1 = i;
                }
            }
        }
        int pos = 0;
        if (p1 && p2 && p3) {
            pos = p1 * p2 * p3;
        }
        int neg = 0;
        if (n1 && n2) {
            neg = n1 * n2 * p3;
        }
        return max(neg, pos);
    }
};