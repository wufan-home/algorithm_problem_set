/*
  Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
            
        TreeNode *left = root->left;
        flatten(left);
        TreeNode *right = root->right;
        flatten(right);
        
        if(left)
        {
            TreeNode *tail = left;
            for(; tail->right != NULL; tail = tail->right) {}
            TreeNode *temp = root->right;
            root->left = NULL;
            root->right = left;
            tail->right = temp;
        }
    }
};
