#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > rv;
	if(root == NULL)
		return rv;

	TreeNode *p_cur = NULL;
	queue<TreeNode *> node_queue;
	node_queue.push(root);	
	int level_size = 0;
	int level_number = -1;
	while(!node_queue.empty())
	{
		if(level_size == 0)
		{
			level_size = node_queue.size();
			rv.push_back(vector<int>());
			++level_number;
		}
		
		p_cur = node_queue.front();
		node_queue.pop();
		--level_size;

		if(level_number % 2 == 1)
			rv[level_number].insert(rv[level_number].begin(), p_cur->val);
		else
			rv[level_number].push_back(p_cur->val);

		if(p_cur->left)
			node_queue.push(p_cur->left);

		if(p_cur->right)
			node_queue.push(p_cur->right);
	}

	return rv;
}
