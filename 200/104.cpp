/*
  Given a binary tree, find its maximum depth.
  The maximum depth is the number of nodes along the longest path 
  from the root node down to the farthest leaf node.
*/

// Recursive.
void maxDepthAux(TreeNode *root, int cur, int& max_length)
{
        if(root->left == NULL && root->right == NULL)
        {
		if(cur > max_length)
			max_length = cur;
        }
        else
        {
		if(root->left)
			maxDepthAux(root->left, cur + 1, max_length);
                
		if(root->right)
			maxDepthAux(root->right, cur + 1, max_length);
        }
}
    
int maxDepth(TreeNode* root) {
        if(root == NULL)
		return 0;
	
        int max_length = 0;
        maxDepthAux(root, 1, max_length);
        return max_length;
}

// Iterative.
int maxDepth1(TreeNode* root) {
        if(root == NULL)
		return 0;
	
        int max_len = 0;
	stack<TreeNode *> node_stack;
	TreeNode *cur = root;
	int cur_len = 0;
	bool visited = false;
	while(cur || !node_stack.empty())
	{
		if(cur)
		{
			++cur_len;
			node_stack.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = node_stack.top();

			if(cur->left == NULL && cur->right == NULL)
				max_len = max(max_len, cur_len);

			if(cur->right && !visited)
				cur = cur->right;
			else
			{
				--cur_len;
				node_stack.pop();
				if(!node_stack.empty())
					visited = (cur == node_stack.top()->right);
				cur = NULL;
			}
		}
	}
	
	
        return max_len;
}
