/*
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    Example 1:
        2
       / \
      1   3
    Binary tree [2,1,3], return true.
    Example 2:
        1
       / \
      2   3
    Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) {
        return root == NULL || 
            (root->val > getMaximalValue(root->left) && 
                root->val <= getMinimalValue(root->right) &&
                isValidBST(root->left) && 
                isValidBST(root->right));
    }
    
private:
    int getMaximalValue(TreeNode *root)
    {
        if(root == NULL)
            return INT_MIN;
            
        while(root->right)
            root = root->right;
            
        return root->val;
    }
    
    int getMinimalValue(TreeNode *root)
    {
        if(root == NULL)
            return INT_MAX;
        
        while(root->left)
            root = root->left;
            
        return root->val;
    }
};
