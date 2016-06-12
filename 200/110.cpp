/*
  Given a binary tree, determine if it is height-balanced.
  For this problem, a height-balanced binary tree is defined as 
  a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

bool checkBalance(TreeNode *root, int& depth)
{
	if(root == NULL)
	{
		depth = 0;
		return true;
	}
	else
	{
		int left = 0;
		int right = 0;
		if(!checkBalance(root->left, left) || !checkBalance(root->right, right))
			return false;

		depth = max(left , right) + 1;
		return abs(left - right) <= 1;
	}
}

bool isBalanced(TreeNode* root) {
        int depth = 0;
	return checkBalance(root, depth);
}

int checkBalance1(TreeNode *root)
{
	if(root == NULL)
    		return 0;
    	else
    	{
    		int left = 0;
    		int right = 0;
    		if((left = checkBalance1(root->left)) == -1 || (right = checkBalance1(root->right)) == -1)
    			return -1;
    
    		return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    	}
}

bool isBalanced1(TreeNode* root) {
	return checkBalance1(root) != -1;
}
