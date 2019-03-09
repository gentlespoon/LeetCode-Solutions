// github.com/gentlespoon
// 0021 - Easy - Merge Two Sorted Lists
// 2019-03-10-03-19-59
// 2019-03-10-03-38-29
// Runtime: 12 ms, faster than 99.32% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 10.1 MB, less than 51.21% of C++ online submissions for Merge Two Sorted Lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        return head->next;
    }
};