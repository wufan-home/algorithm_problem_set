/*
   Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
    Given binary tree [1,null,2,3],
       1
        \
         2
        /
       3
    return [1,3,2].

    Note: Recursive solution is trivial, could you do it iteratively? 
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
    vector<int> inorderTraversal(TreeNode* root) {
        listOfNodeValues = vector<int>();
        getNodeValuesByInorderTraversal(root);
        return listOfNodeValues;
    }
    
private:
    void getNodeValuesByInorderTraversal(TreeNode *root)
    {
        if(root == NULL)
            return;
            
        getNodeValuesByInorderTraversal(root->left);    
        listOfNodeValues.push_back(root->val);
        getNodeValuesByInorderTraversal(root->right);
    }

    vector<int> listOfNodeValues;
};
