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

int sumNumbers(TreeNode* root) {
        if(root == NULL)
		return 0;

	stack<TreeNode *> node_stack;
	TreeNode *cur = root;
	bool visited = false;
	long long num = 0;
	int sum = 0;
	while(cur || !node_stack.empty())
	{
		if(cur)
		{
			num *= 10;
			num += cur->val;
			node_stack.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = node_stack.top();

			if(cur->right && !visited)
				cur = cur->right;
			else
			{
				if(cur->left == NULL && cur->right == NULL)
					sum += num;

				num /= 10;
				node_stack.pop();
				visited = (cur == node_stack.top()->right);
				cur = NULL;
			}
		}
	}

	return sum;
}

