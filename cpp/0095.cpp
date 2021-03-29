/*
	Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

	For example,
	Given n = 3, your program should return all 5 unique BST's shown below.

	   1         3     3      2      1
		\       /     /      / \      \
		 3     2     1      1   3      2
		/     /       \                 \
	   2     1         2                 3
*/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        
        return *doGenerate(1, n);
    }
    
private:
    vector<TreeNode *> *doGenerate(int start, int end)
    {
        vector<TreeNode *> *res = new vector<TreeNode *>();
        if(start > end)
        {
            res->push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode *> *left = doGenerate(start, i - 1);
            vector<TreeNode *> *right = doGenerate(i + 1, end);
            
            for(int k = 0; k < left->size(); ++k)
            {
                for(int j = 0; j < right->size(); ++j)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = (*left)[k];
                    root->right = (*right)[j];
                    res->push_back(root);
                }
            }
        }
        
        return res;
    }
};
