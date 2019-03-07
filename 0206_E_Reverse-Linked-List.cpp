// github.com/gentlespoon
// 0206 - Easy - Roman to Integer
// 2019-03-06-16-17-43
// 2019-03-06-16-33-52
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.2 MB, less than 53.44% of C++ online submissions for Reverse Linked List.

/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current != NULL) {
            ListNode* swap = current->next;
            current->next = prev;
            prev = current;
            current = swap;
        }
        return prev;
    }
};