// 102.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

/*vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int> > levels;
	if (root == NULL)
		return levels;

	TreeNode *p_cur = NULL;
	queue<TreeNode *> node_queue;
	node_queue.push(root);
	node_queue.push(NULL);
	vector<int> level;
	while (p_cur || !node_queue.empty())
	{
		p_cur = node_queue.front();
		node_queue.pop();
		if (p_cur == NULL)
		{
			levels.push_back(level);
			level.clear();
			if (node_queue.front() == NULL)
				break;
			node_queue.push(NULL);
		}
		else
		{
			level.push_back(p_cur->val);

			if (p_cur->left)
				node_queue.push(p_cur->left);

			if (p_cur->right)
				node_queue.push(p_cur->right);
		}
	}

	return levels;
}

int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;

	int max_length = 0;
	int length = 0;
	TreeNode *p_cur = root;
	stack<TreeNode *> node_stack;
	bool bVisited = false;
	while (p_cur || !node_stack.empty())
	{
		if (p_cur)
		{
			node_stack.push(p_cur);
			p_cur = p_cur->left;
			++length;
		}
		else
		{
			p_cur = node_stack.top();
			if (p_cur->right && !bVisited)
			{
				p_cur = p_cur->right;
				continue;
			}
			
			if (p_cur->right == NULL && length > max_length)
			{
				max_length = length;
			}
				
			node_stack.pop();
			--length;
			bVisited = (node_stack.empty() || p_cur == node_stack.top()->right);
			p_cur = NULL;
		}
	}

	return max_length;
}*/

TreeNode *BuildTreeAux(vector<int>& preorder, int start1, int end1,
	vector<int>& inorder, int start2, int end2)
{
	if (start1 > end1 || start2 > end2)
		return NULL;

	int i = start2;
	for (; i <= end2; ++i)
	{
		if (preorder[start1] == inorder[i])
			break;
	}

	TreeNode *root = new TreeNode(preorder[start1]);
	root->left = BuildTreeAux(preorder, start1 + 1, start1 + (i - start2), inorder, start2, i - 1);
	root->right = BuildTreeAux(preorder, start1 + (i - start2 + 1), end1, inorder, i + 1, end2);

	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return BuildTreeAux(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{
	int a[] = {0, 2, 1, 3, 5, 4, 6};
	vector<int> p(a, a + sizeof(a) / sizeof(int));
	int b[] = { 1, 2, 3, 0, 4, 5, 6 };
	vector<int> q(b, b + sizeof(b) / sizeof(int));
	buildTree(p, q);
    return 0;
}

