/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

  Solution:
  
*/

#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > levelOrderBottom(TreeNode* root) {
	vector<vector<int> > result;
	if(root == NULL)
		return result;

	TreeNode *cur = NULL;
	queue<TreeNode *> node_queue;
	node_queue.push(root);
	int level = node_queue.size();
	vector<int> line;
	while(!node_queue.empty())
	{
		cur = node_queue.front();
		node_queue.pop();
		--level;

		line.push_back(cur->val);
		if(cur->left)
			node_queue.push(cur->left);
		if(cur->right)
			node_queue.push(cur->right);

		if(!level)
		{
			level = node_queue.size();
			result.insert(result.begin(), line);
			line.clear();
		}
	}

	return result;
}
