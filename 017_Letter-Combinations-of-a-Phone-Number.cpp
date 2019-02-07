/*
Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

 */



// GentleSpoon me@gentlespoon.com
// Leetcode    Q17
// Start       2018-01-02-22-18-54
// Finish      2018-01-02-22-39-23

// BFS

class Solution {
public:
    vector<string> map = {
        " ",           // 0
        "",            // 1
        "abc",         // 2
        "def",         // 3
        "ghi",         // 4
        "jkl",         // 5
        "mno",         // 6
        "pqrs",        // 7
        "tuv",         // 8
        "wxyz"         // 9
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret = {""};
        if (!digits.length()) return {};
        for (char digit : digits) {
            digit -= '0';
            vector<string> tmp;
            for (string str : ret) {
                for (char chr : map[digit]) {
                    tmp.push_back(str + chr);
                }
            }
            ret = tmp;
        }
        // for (string str : ret) {
        //     cout << str << endl;
        // }
        return ret;
    }
};