/*
    Given a binary tree, find the length of the longest path where each node in the path has the same value. 
    This path may or may not pass through the root.

    Note: The length of path between two nodes is represented by the number of edges between them.

    Example 1:

    Input:

                  5
                 / \
                4   5
               / \   \
              1   1   5
    Output:

    2
    Example 2:

    Input:

                  1
                 / \
                4   5
               / \   \
              4   4   5
    Output:

    2
    Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;

        int maxLen = 1;
        checkPathLen(root, maxLen);
        return maxLen - 1;
    }
    
private:
    int checkPathLen(TreeNode *root, int& maxLen)
    {
        if(root == NULL)
            return 0;
        
        int res = 1;
        int len = 1;
        int left = checkPathLen(root->left, maxLen);
        if(root->left && root->val == root->left->val)
        {
            res += left;
            len += left;
            maxLen = max(maxLen, len);
        }
        
        int right = checkPathLen(root->right, maxLen);
        if(root->right && root->right->val == root->val)
        {
            len += right;
            res = max(res, 1 + right);
            maxLen = max(maxLen, len);
        }
        
        return res;
    }
};
