// github.com/gentlespoon
// 0094 - Medium - Binary Tree Inorder Traversal 
// Optimized memory usage
// Start       2019-03-06-14-07-25
// Finish      2019-03-06-14-23-14
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.5 MB, less than 15.33% of C++ online submissions for Binary Tree Inorder Traversal.


/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> ans;
    int level = 0;
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ansL;
        if (root == NULL) {
            return ansL;
        }
        // vector<int> ansR;
        level++;
        inorderTraversal(root->left);
        level--;
        ans.push_back(root->val);
        // ansR = inorderTraversal(root->right);
        level++;
        inorderTraversal(root->right);
        level--;
        // for (int r : ansR) {
            // ansL.push_back(r);
        // }
        if (!level) return ans;
        return ansL;
    }
};