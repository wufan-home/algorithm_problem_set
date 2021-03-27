/*
	Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

	Note: 
	You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

	Follow up:
	What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

	Credits:
	Special thanks to @ts for adding this problem and creating all test cases.
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v(k, 0);
        getValues(root, v, 0);
        return v.back();
    }
    
private:
    void getValues(TreeNode *root, vector<int>& v, int cur)
    {
        if(root == NULL || cur == v.size())
            return;
        
        getValues(root->left, v, cur);
        if(cur == v.size())
            return;
        v[cur++] = root->val;
        getValues(root->right, v, cur);
    }
};
