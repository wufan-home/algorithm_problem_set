// 297.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result("");
		if (root == NULL)
			return result;

		vector<int> values;
		queue<TreeNode *> node_queue;
		node_queue.push(root);
		while (!node_queue.empty())
		{
			TreeNode *p_cur = node_queue.front();
			node_queue.pop();

			if (p_cur == NULL)
			{
				values.push_back(INT_MIN);
				continue;
			}
			else
			{
				values.push_back(p_cur->val);
				node_queue.push(p_cur->left);
				node_queue.push(p_cur->right);
			}
		}

		for (int i = 0; i < values.size(); ++i)
		{
			if (i > 0)
				result.push_back(',');
			if (values[i] == INT_MIN)
				result.append("null");
			else
				result.append(to_string(values[i]));
		}

		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		queue<string> sValues;
		char *temp = new char[data.size() + 1];
		memset(temp, '\0', data.size() + 1);
		for (int i = 0; i < data.size(); ++i)
			temp[i] = data[i];
		char *next_token1 = NULL;
		char *token = strtok_s(temp, ",", &next_token1);
		while (token != NULL)
		{
			sValues.push(string(token));
			token = strtok_s(NULL, ",", &next_token1);
		}
		delete[] temp;

		if (sValues.empty() || sValues.front() == "null")
			return NULL;

		TreeNode *root = new TreeNode(atoi(sValues.front().c_str()));
		queue<TreeNode *> node_queue;
		node_queue.push(root);
		sValues.pop();
		while (!node_queue.empty() && !sValues.empty())
		{
			TreeNode *p_cur = node_queue.front();
			node_queue.pop();
			if (sValues.front() != "null")
			{
				p_cur->left = new TreeNode(atoi(sValues.front().c_str()));
				node_queue.push(p_cur->left);
			}

			sValues.pop();

			if (!sValues.empty() &&  sValues.front() != "null")
			{
				p_cur->right = new TreeNode(atoi(sValues.front().c_str()));
				node_queue.push(p_cur->right);
			}

			sValues.pop();
		}

		return root;
	}


int main()
{
	string str("1,2,3,null,null,4,5");
	cout << serialize(deserialize(str)) << endl;
    return 0;
}

