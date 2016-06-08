/*
  Given preorder and inorder traversal of a tree, construct the binary tree.
  Note:
  You may assume that duplicates do not exist in the tree.

  Solution:
  Recursive method: The first element of every sub-array is the value of the root of the sub-tree.
  Since the value of every node is not same, find the left and right parts from the inorder array
  which is seperated by the value.

  From this method, we know that the in-order array is used to describe the left sub-tree and
  the right sub-tree.
*/

#include <vector>

using namespace std;

TreeNode *build(vector<int>& pre, int s1, int e1, vector<int>& in, int s2, int e2)
{
    	int v = pre[s1];
    	int ltend = s2 - 1;
	    int rtstart = e2 + 1;
    	for(int i = s2; i <= e2; ++i)
    	{
    		if(in[i] == v)
    		{
    			ltend = i - 1;
    			rtstart = i + 1;
    			break;
    		}
    	}
    	TreeNode *root = new TreeNode(v);
    	if(s2 <= ltend)
    		root->left = build(pre, s1 + 1, s1 + (ltend - s2) + 1, in, s2, ltend);
    	if(rtstart <= e2)
    		root->right = build(pre, s1 + (ltend - s2) + 2, e1, in, rtstart, e2);
    	return root;
}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
        if(preorder.empty() || preorder.size() != inorder .size())
		    return NULL;    

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
