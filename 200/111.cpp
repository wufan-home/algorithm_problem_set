/*
	Given a binary tree, find its minimum depth.

	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    Solution() : minimumDepth(INT_MAX) {}
    
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int curDepth = 1;
        calculateDepth(root, curDepth);
        return minimumDepth;
    }
private:
    void calculateDepth(TreeNode *root, int curDepth)
    {
        if(root->left == NULL && root->right == NULL)
        {
            minimumDepth = min(minimumDepth, curDepth);
            return;
        }
        
        if(root->left)
            calculateDepth(root->left, curDepth + 1);
            
        if(root->right)
            calculateDepth(root->right, curDepth + 1);
    }
    
    int minimumDepth;
};
