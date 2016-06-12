/*
  Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

    Solution: This problem cannnot be solved by the recursive method, since its structure is not symmetric.
*/

TreeLinkNode *GetNextNode(TreeLinkNode *cur)
{
	for(; cur->next && cur->left  == NULL && cur->right == NULL; cur = cur->next) {}
	return cur->left ? cur->left : cur->right;
}

void connect(TreeLinkNode *root) {
        if(root == NULL)
		return;

	queue<TreeLinkNode *> node_queue;
	node_queue.push(root);
	while(!node_queue.empty())
	{
		TreeLinkNode *cur = node_queue.front();
		node_queue.pop();
		if(cur->left)
		{
			if(cur->right)
				cur->left->next = cur->right;
			else if(cur->next)
				cur->left->next = GetNextNode(cur->next);
			node_queue.push(cur->left);
		}
		
		if(cur->right)
		{
			if(cur->next)
				cur->right->next = GetNextNode(cur->next);
			node_queue.push(cur->right);
		}
	}
}
