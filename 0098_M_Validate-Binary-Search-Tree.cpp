// github.com/gentlespoon
// 0098 - Medium - Validate Binary Search Tree
// 2019-03-12-21-34-24
// 2019-03-12-22-06-03
// Runtime: 20 ms, faster than 99.60% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 21 MB, less than 12.48% of C++ online submissions for Validate Binary Search Tree.



/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
    2
   / \
  1   3
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root==NULL) { return; }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }


    bool isValidBST(TreeNode* root) {
        if (root==NULL) {
            return true;
        }
        vector<int> nums;
        inorder(root, nums);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
};

/*
          3
       1     5
    0   2   4   6
   - - - 3
*/