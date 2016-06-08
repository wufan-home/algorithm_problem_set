/*
  Given inorder and postorder traversal of a tree, construct the binary tree.
  Note:
  You may assume that duplicates do not exist in the tree.

  Solution:
  Similar with the problem 105.
*/

#include <vector>

using namespace std;

TreeNode *build(vector<int>& in, int s1, int e1, vector<int>& po, int s2, int e2)
{
    	int v = po[e2];
    	int ltend = s1 - 1;
    	int rtstart = e1 + 1;
    	for(int i = s1; i <= e1; ++i)
    	{
    		if(in[i] == v)
    		{
    			ltend = i - 1;
    			rtstart = i + 1;
    			break;
    		}
    	}
    
    	TreeNode *root = new TreeNode(v);
    	if(s1 <= ltend)
    		root->left = build(in, s1, ltend, po, s2, s2 + (ltend - s1));
    	if(rtstart <= e1)
    		root->right = build(in, rtstart, e1, po, s2 + (ltend - s1) + 1, e2 - 1);
    	return root;
}
    
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    	if(inorder.empty() || inorder.size() != postorder.size())
    		return NULL;
    
    	return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
