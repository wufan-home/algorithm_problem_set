/*
  Given a binary tree, determine if it is height-balanced.
  For this problem, a height-balanced binary tree is defined as 
  a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return checkBalance(root, depth);
    }
    
private:
    bool checkBalance(TreeNode *root, int& depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }
        
        int leftDepth = 0;
        int rightDepth = 0;
        if(checkBalance(root->left, leftDepth) == false || 
            checkBalance(root->right, rightDepth) == false || 
            abs(leftDepth - rightDepth) > 1)
            return false;
            
        depth = max(leftDepth, rightDepth) + 1;
        return true;
    }
};
