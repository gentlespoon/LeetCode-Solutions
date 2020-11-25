/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6


Return null for empty list.
*/


// GentleSpoon me@gentlespoon.com
// Leetcode    Q023
// Start       2019-02-20-14-37-32
// Finish      2019-02-20-14-56-04


/*
Runtime: 356 ms, faster than 32.54% of JavaScript online submissions for Merge k Sorted Lists.
Memory Usage: 38.1 MB, less than 63.08% of JavaScript online submissions for Merge k Sorted Lists.
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (!lists.length) return null;
    
    var head = new ListNode(null);
    var tail = head;
    var minIndex;
    while (lists.length) {
        for (var row=lists.length-1; row>=0; row--) {
            if (!lists[row]) lists.splice(row, 1);
        }
        minIndex = minNodeIndex(lists);
        if (minIndex === null) break;
        if (head.val === null) {
            head.val = lists[minIndex].val;
        } else {
            tail.next = new ListNode(lists[minIndex].val);
            tail = tail.next;
        }
        lists[minIndex] = lists[minIndex].next;
    }
    return head.val!==null ? head : null;
};

var minNodeIndex = function(lists) {
    var minValue = null;
    var minIndex = null;
    for (var row=lists.length-1; row>=0; row--) {
        if (minValue===null || minValue>lists[row].val) {
            minValue = lists[row].val;
            minIndex = row;
        }
    }
    // console.log(minIndex, minValue)
    return minIndex;
}
         
         
         
/* complexity:

    O(kN)
*/
         
