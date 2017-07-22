/*
    Given a binary tree, find the length of the longest consecutive sequence path.

    The path refers to any sequence of nodes from some starting node to any node in the tree 
    along the parent-child connections. 
    The longest consecutive path need to be from parent to child (cannot be the reverse).

    For example,
       1
        \
         3
        / \
       2   4
            \
             5
    Longest consecutive sequence path is 3-4-5, so return 3.
       2
        \
         3
        / 
       2    
      / 
     1
    Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root == NULL ? 0 : 1;
        
        int maxLen = 0;
        int maxLenFromRoot = 0;
        countLongestPath(root, maxLen, maxLenFromRoot);
        
        return maxLen;
    }
    
private:
    void countLongestPath(TreeNode *root, int &maxLen, int &maxLenFromRoot)
    {
        if(root == NULL)
        {
            maxLen = 0;
            maxLenFromRoot = 0;
            return;
        }
        
        int maxLenLeft = 0;
        int maxLenFromRootLeft = 0;
        countLongestPath(root->left, maxLenLeft, maxLenFromRootLeft);
        maxLenFromRoot = max(maxLenFromRoot, 
                             1 + (root->left && root->val == root->left->val - 1 ? maxLenFromRootLeft : 0));
        maxLen = max(maxLen, max(maxLenLeft, maxLenFromRoot));
                         
        int maxLenRight = 0;
        int maxLenFromRootRight = 0;
        countLongestPath(root->right, maxLenRight, maxLenFromRootRight);
        maxLenFromRoot = max(maxLenFromRoot, 
                             1 + (root->right && root->val == root->right->val - 1 ? maxLenFromRootRight : 0));
        maxLen = max(maxLen, max(maxLenRight, maxLenFromRoot));
        
        maxLen = max(maxLen, max(maxLenLeft, maxLenRight));
    }
};
