// github.com/gentlespoon
// 0397 - Medium - Integer Replacement
// 2020-01-08T19:11:10-07:00
// 2020-01-08T19:23:03-07:00
// Runtime: 40 ms, faster than 100.00% of C# online submissions for Integer Replacement.
// Memory Usage: 14.6 MB, less than 100.00% of C# online submissions for Integer Replacement.


/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

public class Solution {
    public int IntegerReplacement(int n) {
      int i = 0;
      i = recurrivePart(n, i);
      return i;
    }
  
    public int recurrivePart(int n, int i)
    {
      switch (n)
      {
        case int.MaxValue:
          return 32;
        case 1:
          return i;
        default:
          i++;
          return (n & 1) == 0 ?
            recurrivePart(n >> 1, i) :
            Math.Min(recurrivePart(n - 1, i), recurrivePart(n + 1, i));
      }
    }
}
