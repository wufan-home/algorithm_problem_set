// 099.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode* root) {
	if (root == NULL)
		return;

	stack<TreeNode *> node_stack;
	TreeNode *p_cur = root;
	TreeNode *last = NULL;
	vector<TreeNode *> wrong_nodes;
	while (p_cur || !node_stack.empty())
	{
		if (p_cur)
		{
			node_stack.push(p_cur);
			p_cur = p_cur->left;
		}
		else
		{
			p_cur = node_stack.top();
			if (last && last->val > p_cur->val)
			{
				wrong_nodes.push_back(last);
				wrong_nodes.push_back(p_cur);
			}

			last = p_cur;
			node_stack.pop();
			p_cur = p_cur->right;
		}
	}

	if (wrong_nodes.size() == 2)
		swap(wrong_nodes[0]->val, wrong_nodes[1]->val);
	else
		swap(wrong_nodes[0]->val, wrong_nodes[3]->val);
}

int main()
{
	TreeNode *head = new TreeNode(2);
	head->left = new TreeNode(3);
	head->right = new TreeNode(1);
	recoverTree(head);
    return 0;
}

