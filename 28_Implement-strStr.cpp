/*

Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/

// GentleSpoon <me@gentlespoon.com>
// Q028
// 2019-02-27-22-02-50
// 2019-02-27-22-09-33

/*
Runtime: 8 ms, faster than 99.35% of C++ online submissions for Implement strStr().
Memory Usage: 9.7 MB, less than 15.73% of C++ online submissions for Implement strStr().
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs = haystack.size(), ns = needle.size();
        if (!ns) return 0;
        if (ns>hs) return -1;
        for(int i = 0; i <= hs-ns; i ++)
            if (haystack.substr(i, ns) == needle) return i; 
        return -1;
    }
};
