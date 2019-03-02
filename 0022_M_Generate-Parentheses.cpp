// github.com/gentlespoon
// 0022 - Medium - Generate Parentheses
// 2019-03-01-15-59-34
// 2019-03-01-16-03-52
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
// Memory Usage: 17.4 MB, less than 32.14% of C++ online submissions for Generate Parentheses.

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen(result, "", n, 0);
        return result;
    }

    void gen(vector<string>& result, string str, int l, int r) {
        if (l==0 && r==0) {
            result.push_back(str);
            return;
        }
        if (l) gen(result, str+"(", l-1, r+1);
        if (r) gen(result, str+")", l, r-1);
    }
};
