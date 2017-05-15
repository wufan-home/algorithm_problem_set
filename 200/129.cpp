/*
	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
	An example is the root-to-leaf path 1->2->3 which represents the number 123.
	Find the total sum of all root-to-leaf numbers.
	For example,

		1
	   / \
	  2   3
	The root-to-leaf path 1->2 represents the number 12.
	The root-to-leaf path 1->3 represents the number 13.
	Return the sum = 12 + 13 = 25.
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
    Solution() : current(0), sum(0) {}
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        calculateSum(root);
        return sum;
    }
private:
    void calculateSum(TreeNode *root)
    {
        current = 10 * current + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += current;
            current /= 10;
            return;
        }
        
        if(root->left)
            calculateSum(root->left);
            
        if(root->right)
            calculateSum(root->right);
            
        current /= 10;
    }

    int current;
    int sum;
};
