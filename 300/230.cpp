#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
		return INT_MIN;

	stack<TreeNode *> node_stack;
	TreeNode *p_cur = root;
	int result = INT_MIN;
	while(p_cur || !node_stack.empty())
	{
		if(p_cur)
		{
			node_stack.push(p_cur);
			p_cur = p_cur->left;
		}
		else
		{
			p_cur = node_stack.top();
			node_stack.pop();
			--k;
			if(k == 0)
			{
				result = p_cur->val;
				break;
			}

			p_cur = p_cur->right;
		}
	}

	return result;
}
