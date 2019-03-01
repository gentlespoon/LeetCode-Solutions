// github.com/gentlespoon
// 0002 - Medium - Add Two Numbers
// Start       2019-02-07-23-33-07
// Finish      2019-02-07-23-43-51
// Runtime: 140ms, beats 54.34% of javascript submissions.

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/


/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var carry = 0;
    var digit;
    var head = new ListNode(0);
    var current = head;
    var x, y;
    while (l1 !== null || l2 !== null) {
        x = 0;
        if (l1 !== null) {
            x = l1.val;
            l1 = l1.next;
        }
        y = 0;
        if (l2 !== null) {
            y = l2.val
            l2 = l2.next;
        }
        digit = x+y+carry;
        carry = digit>9?1:0;
        current.next = new ListNode(digit%10);
        current = current.next;
    }
    if (carry) {
        current.next = new ListNode(carry);
    }
    return head.next;
};
