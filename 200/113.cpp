/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
				  5
				 / \
				4   8
			   /   / \
			  11  13  4
			 /  \    / \
			7    2  5   1
	return
	[
	   [5,4,11,2],
	   [5,8,4,5]
	]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root != NULL)
            getPathSum(root, sum);
        return paths;
    }
private:    
    void getPathSum(TreeNode *root, int sum)
    {
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == root->val)
                paths.push_back(path);
            
            path.pop_back();
            return;
        }
        
        if(root->left)
            getPathSum(root->left, sum - root->val);
            
        if(root->right)
            getPathSum(root->right, sum - root->val);
            
        path.pop_back();
    }
    
    vector<int> path;
    vector<vector<int>> paths;
};
