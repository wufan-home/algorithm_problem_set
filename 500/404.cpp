/*
    Find the sum of all left leaves in a given binary tree.

    Example:

        3
       / \
      9  20
        /  \
       15   7

    There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return sum;

        if(root->left)
        {
            if(root->left->left == NULL && root->left->right == NULL)
                sum += root->left->val;
            else    
                sum += sumOfLeftLeaves(root->left);
        }
        
        if(root->right)
            sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
