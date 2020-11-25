/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5

Explanation:
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

// github.com/gentlespoon
// Q494
// 2019-02-28-08-46-24
// 2019-02-28-08-52-19

/*
Runtime: 1084 ms, faster than 31.96% of C++ online submissions for Target Sum.
Memory Usage: 9.3 MB, less than 82.24% of C++ online submissions for Target Sum.
*/

class Solution {
public:
    int count = 0;
    int ns = 0;
    int S = 0;

    void dfs(vector<int>& nums, int currentSum, int index) {
        if (index >= ns) {
            if (currentSum == S) {
                count++;
            }
            return;
        }
        dfs(nums, currentSum+nums[index], index+1);
        dfs(nums, currentSum-nums[index], index+1);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        ns = nums.size();
        if (!ns) { return 0; }
        this->S = S;
        dfs(nums, 0, 0);
        return count;
    }
};
