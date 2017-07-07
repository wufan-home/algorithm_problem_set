/*
    Given a binary tree, find the leftmost value in the last row of the tree.

    Example 1:
    Input:

        2
       / \
      1   3

    Output:
    1
    Example 2: 
    Input:

            1
           / \
          2   3
         /   / \
        4   5   6
           /
          7

    Output:
    7
    Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        
        int depth = 1;
        int *leftBottomValue = NULL;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur == NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    leftBottomValue = NULL;
                }
                continue;
            }
            
            if(leftBottomValue == NULL)
                leftBottomValue = new int(cur->val);
            
            if(cur->left)
                q.push(cur->left);
            
            if(cur->right)
                q.push(cur->right);
        }
        
        return *leftBottomValue;
    }
};
