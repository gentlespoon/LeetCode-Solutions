/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


 */


// GentleSpoon me@gentlespoon.com
// Leetcode    Q20
// Start       2018-01-02-22-50-18
// Finish      2018-01-02-22-58-21


class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char chr : s) {
            if (
                chr == '(' ||
                chr == '[' ||
                chr == '{'
               ) {
                sta.push(chr);
            }
            
            if (chr == ')') {
                if (sta.top()=='(') {
                    sta.pop();
                } else {
                    return false;
                }
            }
            if (chr == ']') {
                if (sta.top()=='[') {
                    sta.pop();
                } else {
                    return false;
                }
            }
            if (chr == '}') {
                if (sta.top()=='{') {
                    sta.pop();
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};