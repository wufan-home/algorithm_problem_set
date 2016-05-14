void minDepthAux(TreeNode *root, int current_depth, int& min_depth)
{
	if(root->left == NULL && root->right == NULL)
	{
		if(min_depth == 1 || current_depth < min_depth)
			min_depth = current_depth;
	}
	else
	{
		if(root->left != NULL)
			minDepthAux(root->left, current_depth + 1, min_depth);

		if(root->right != NULL)
			minDepthAux(root->right, current_depth + 1, min_depth);
	}
}

int minDepth(TreeNode* root) {
	if(root == NULL)
		return 0;

	int min_depth = 1;
	minDepthAux(root, 1, min_depth);
	return min_depth;
}
