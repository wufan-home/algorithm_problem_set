#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

vector<TreeNode*> generateTrees(int n) {
	if(n == 0)
		return (vector<TreeNode *>(new TreeNode(0)));

	map<int, vector<TreeNode *> *> subtrees;
	for(int len = 1; len <= n; ++len)
	{
		vector<TreeNode *> *roots = new vector<TreeNode *>();
		if(len == 1)
		{
			for(int root_val = 1; root_val <= n; ++i)
				(*roots).push_back(new TreeNode(root_val));
		}
		else
		{
			for(int root_val = 1; root_val <= n; ++root_val)
			{
				int end = root_val + len - 1;
				for(int i = root_val; i <= end; ++i)
				{
					if(i == root_val)
					{
						for(int j = i + 1; j <= end; ++j)
						{
							
							
						}
					}
					else if(i == end)
					{}
					else
					{}
				}
			}
		}

		subtrees[len] = roots;
	}
	return subtrees[n];
}
