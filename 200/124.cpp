/*
	Given a binary tree, find the maximum path sum.

	For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree 
	along the parent-child connections. The path must contain at least one node and does not need to go through the root.

	For example:
	Given the below binary tree,

		   1
		  / \
		 2   3
	Return 6.
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
    int maxPathSum(TreeNode* root) {
        int pathSumOverRoot = INT_MIN;
        int pathSumFromRoot = getMaxPathSum(root, pathSumOverRoot);
        return max(pathSumFromRoot, pathSumOverRoot);
    }
    
private:
    int getMaxPathSum(TreeNode *root, int& maxPathSumOverRoot)
    {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
        {
            maxPathSumOverRoot = max(maxPathSumOverRoot, root->val);
            return root->val;
        }
        
        int localMaxPathSumOverRoot = INT_MIN;
        int leftMaxPathSum = getMaxPathSum(root->left, localMaxPathSumOverRoot);
        int rightMaxPathSum = getMaxPathSum(root->right, localMaxPathSumOverRoot);
        
        int pathSumOverRoot = root->val + max(0, leftMaxPathSum) + max(0, rightMaxPathSum);
        
        maxPathSumOverRoot = max(maxPathSumOverRoot, max(localMaxPathSumOverRoot, pathSumOverRoot));
        
        return root->val + max(0, max(leftMaxPathSum, rightMaxPathSum));
    }
};
