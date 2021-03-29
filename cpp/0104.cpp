/*
  Given a binary tree, find its maximum depth.
  The maximum depth is the number of nodes along the longest path 
  from the root node down to the farthest leaf node.
*/

// Recursive.
class Solution {
public:
    Solution() { maxDepthValue = 0; }

    void detectDepth(const TreeNode *root, int curDepth)
    {
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL)
            maxDepthValue = max(maxDepthValue, curDepth);
        else 
        {
            if(root->left)
                detectDepth(root->left, curDepth + 1);
            
            if(root->right)
                detectDepth(root->right, curDepth + 1);
        }
    }
    
    int maxDepth(TreeNode* root) 
    {
        detectDepth(root, 1);
        return maxDepthValue;
    }
    
private:
    int maxDepthValue;
};

// Iterative.
int maxDepth1(TreeNode* root) {
        if(root == NULL)
		return 0;
	
        int max_len = 0;
	stack<TreeNode *> node_stack;
	TreeNode *cur = root;
	int cur_len = 0;
	bool visited = false;
	while(cur || !node_stack.empty())
	{
		if(cur)
		{
			++cur_len;
			node_stack.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = node_stack.top();

			if(cur->left == NULL && cur->right == NULL)
				max_len = max(max_len, cur_len);

			if(cur->right && !visited)
				cur = cur->right;
			else
			{
				--cur_len;
				node_stack.pop();
				if(!node_stack.empty())
					visited = (cur == node_stack.top()->right);
				cur = NULL;
			}
		}
	}
	
	
        return max_len;
}
