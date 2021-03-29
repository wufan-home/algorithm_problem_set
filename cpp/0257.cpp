/*
	Given a binary tree, return all root-to-leaf paths.

	For example, given the following binary tree:

	   1
	 /   \
	2     3
	 \
	  5
	All root-to-leaf paths are:

	["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return vector<string>();
        
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        
        vector<string> res;
        for(auto a : left)
        {
            res.push_back(to_string(root->val));
            res.back().append("->");
            res.back().append(a);
        }
        
        for(auto a : right)
        {
            res.push_back(to_string(root->val));
            res.back().append("->");
            res.back().append(a);
        }
        
        if(res.empty())
            res.push_back(to_string(root->val));
        
        return res;
    }
};
