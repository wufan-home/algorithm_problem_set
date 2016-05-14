#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

bool isSymmetricAux(TreeNode *l, TreeNode *r)
{
        if((l == NULL && r == NULL) ||
	   (l != NULL && r != NULL && l->val == r->val &&
	    isSymmetricAux(l->left, r->right) &&
	    isSymmetricAux(l->right, r->left)))
	   return true;
	   
    	return false;
}
    
bool isSymmetric(TreeNode* root) {
        if(!root)
    		return true;
    
    	return isSymmetricAux(root->left, root->right);
}
