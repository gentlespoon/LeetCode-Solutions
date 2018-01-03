/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.


 */




// GentleSpoon me@gentlespoon.com
// Leetcode    Q66
// Start       2018-01-02-23-18-34
// Finish      2018-01-02-23-23-58

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        for (int i=size-1; i>=0; i--) {
            digits[i] += carry;
            if (digits[i]>9) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            digits.insert (digits.begin(), 1);
        }
        // for (int d : digits) {
        //     cout << d;
        // }
        return digits;
    }
};