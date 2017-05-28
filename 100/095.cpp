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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        valueRangeToTreeNodes[""] = vector<TreeNode *>();
        return getListOfTreeWithGivenRange(1, n);
    }
    
private:
    vector<TreeNode *>& getListOfTreeWithGivenRange(int start, int end)
    {
        if(start > end)
            return valueRangeToTreeNodes[""];
            
        string range = to_string(start).append(to_string(end));
        if(valueRangeToTreeNodes.find(range) != valueRangeToTreeNodes.end())
            return valueRangeToTreeNodes[range];

        valueRangeToTreeNodes[range] = vector<TreeNode *>();
        if(start == end)
        {
            valueRangeToTreeNodes[range].push_back(new TreeNode(start));
            return valueRangeToTreeNodes[range];
        }
        
        for(int rootValue = start; rootValue <= end; ++rootValue)
        {
            vector<TreeNode *> &leftSubtrees = getListOfTreeWithGivenRange(start, rootValue - 1);
            vector<TreeNode *> &rightSubtrees = getListOfTreeWithGivenRange(rootValue + 1, end);
            
            if(leftSubtrees.empty())
            {
                for(int i = 0; i < rightSubtrees.size(); ++i)
                {
                    TreeNode *root = new TreeNode(rootValue);
                    root->right = rightSubtrees[i];
                    valueRangeToTreeNodes[range].push_back(root);
                }
            }
            else if(rightSubtrees.empty())
            {
                for(int i = 0; i < leftSubtrees.size(); ++i)
                {
                    TreeNode *root = new TreeNode(rootValue);
                    root->left = leftSubtrees[i];
                    valueRangeToTreeNodes[range].push_back(root);
                }
            }
            else
            {
                for(int i = 0; i < leftSubtrees.size(); ++i)
                {
                    for(int j = 0; j < rightSubtrees.size(); ++j)
                    {
                        TreeNode *root = new TreeNode(rootValue);
                        root->left = leftSubtrees[i];
                        root->right = rightSubtrees[j];
                        valueRangeToTreeNodes[range].push_back(root);
                    }
                }
            }
        }
        
        return valueRangeToTreeNodes[range];
    }

    unordered_map<string, vector<TreeNode *>> valueRangeToTreeNodes;
};
