/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <vector>

using namespace std;

void generate(TreeNode *root, int sum, vector<int>& path, vector<vector<int> >& result)
{
        if(root == NULL)
            return;
    	else if(root->left == NULL && root->right == NULL)
    	{
    		if(sum == root->val)
    		{
    		    path.push_back(root->val);
    			result.push_back(path);
    			path.pop_back();
    		}
    	}
    	else
    	{
    		path.push_back(root->val);
    		generate(root->left, sum - root->val, path, result);
    		generate(root->right, sum - root->val, path, result);
    		path.pop_back();
    	}
}
    
vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    	vector<vector<int> > result;
    	if(root == NULL)
    		return result;
    
    	vector<int> path;
    	generate(root, sum, path, result);
    	return result;
}

vector<vector<int> > pathSum1(TreeNode *root, int sum)
{
	vector<vector<int> > result;
	if(root == NULL)
		return result;

	vector<int> path;
	stack<TreeNode *> node_stack;
	TreeNode *cur = root;
	bool visited = false;
	while(cur || !node_stack.empty())
	{
		if(cur)
		{
			node_stack.push(cur);
			sum -= cur->val;
			path.push_back(cur->val);
			cur = cur->left;
		}
		else
		{
			cur = node_stack.top();
			if(cur->right && !visited)
				cur = cur->right;
			else
			{
				if(cur->left == NULL && cur->right == NULL && sum == 0)
					result.push_back(path);

				path.pop_back();
				sum += cur->val;
				node_stack.pop();
				if(!node_stack.empty())
					visited = (cur == node_stack.top()->right);
				cur = NULL;
			}
		}
	}

	return result;
}
