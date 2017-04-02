/*
	Two elements of a binary search tree (BST) are swapped by mistake.
	Recover the tree without changing its structure.
	Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

void recoverTree(TreeNode* root) 
{
	vector<TreeNode *> candidates;
	vector<int> candidate_values;

	stack<TreeNode *> stackForTree;
	TreeNode *curNode = root;
	TreeNode *lastNode = NULL;
	while(curNode != NULL || !stackForTree.empty())
	{
		if(curNode)
		{
			stackForTree.push(curNode);
			curNode = curNode->left;
		}
		else
		{
			curNode = stackForTree.top();
			stackForTree.pop();

			if(lastNode != NULL && lastNode->val > curNode->val)
			{
				candidates.push_back(lastNode);
				candidate_values.push_back(lastNode->val);
				candidates.push_back(curNode);
				candidate_values.push_back(curNode->val);
			}

			lastNode = curNode;
			curNode = curNode->right;
		}
	}

	sort(candidate_values.begin(), candidate_values.end());
	for(int i = 0; i < candidate_values.size(); ++i)
		candidates[i]->val = candidate_values[i];
}

TreeNode *findIncorrectNodes(TreeNode *root, TreeNode *lastNode, vector<TreeNode *>& candidates, vector<int>& candidate_values)
{
	if(root->left)
		lastNode = findIncorrectNodes(root->left, lastNode, candidates, candidate_values);

	if(lastNode != NULL && lastNode->val > root->val)
	{
		candidates.push_back(lastNode);
		candidate_values.push_back(lastNode->val);
		candidates.push_back(root);
		candidate_values.push_back(root->val);
	}
	lastNode = root;

	if(root->right)
		lastNode = findIncorrectNodes(root->right, lastNode, candidates, candidate_values);

	return lastNode;
}

void recoverTree(TreeNode* root) 
{
	vector<TreeNode *> candidates;
	vector<int> candidate_values;

	TreeNode *lastNode = NULL;
	findIncorrectNodes(root, lastNode, candidates, candidate_values);

	sort(candidate_values.begin(), candidate_values.end());
	for(int i = 0; i < candidate_values.size(); ++i)
		candidates[i]->val = candidate_values[i];
}
