// 257.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> results;
	if (root == NULL)
		return results;

	vector<string> s_number_list(1000, "");
	int cur = 0;
	TreeNode *p_cur = root;
	stack<TreeNode *> node_stack;
	bool visited = false;
	while (p_cur || !node_stack.empty()) {
		if (p_cur) 
		{
			s_number_list[cur++] = (to_string(p_cur->val));
			node_stack.push(p_cur);
			p_cur = p_cur->left;
		}
		else 
		{
			p_cur = node_stack.top();

			if (p_cur->left == NULL && p_cur->right == NULL)
			{
				string path("");
				for (int curl = 0; curl < cur; ++curl)
				{
					if (!path.empty())
						path.append("->");
					path.append(s_number_list[curl]);
				}
				results.push_back(path);
			}
			else if (p_cur->right != NULL)
			{
				if (!visited)
				{
					p_cur = node_stack.top()->right;
					continue;
				}
			}

			--cur;

			node_stack.pop();
			if (!node_stack.empty())
				visited = (p_cur == node_stack.top()->right);
			p_cur = NULL;
		}
	}

	return results;
}

int main()
{
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);
	vector<string> results = binaryTreePaths(head);
	for (int i = 0; i < results.size(); ++i)
		cout << results[i] << endl;

	delete head;
    return 0;
}

