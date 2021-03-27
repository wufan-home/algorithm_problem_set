/*
    Given a binary tree, count the number of uni-value subtrees.

    A Uni-value subtree means all nodes of the subtree have the same value.

    For example:
    Given binary tree,
                  5
                 / \
                1   5
               / \   \
              5   5   5
    return 4.
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
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL)
            return 0;

        int uniValue;
        checkUniSubtree(root, uniValue);
        return numOfUniSubTree;
    }
    
private:
    bool checkUniSubtree(TreeNode *root, int &uniValue)
    {
        int leftUniValue = INT_MIN;
        bool leftUniSubtree = (root->left == NULL || checkUniSubtree(root->left, leftUniValue));
                                
        int rightUniValue = INT_MIN;
        bool rightUniSubtree = (root->right == NULL || checkUniSubtree(root->right, rightUniValue));
    
        if(leftUniSubtree == false || rightUniSubtree == false)
        {
            uniValue = INT_MIN;
            return false;
        }
        
        if((root->left != NULL && leftUniValue != root->val) || (root->right != NULL && rightUniValue != root->val)) 
        {
            uniValue = INT_MIN;
            return false;
        }
        
        ++numOfUniSubTree;
        uniValue = root->val;
        return true;
    }
    
    int numOfUniSubTree;
};
