/*
    You are given a binary tree in which each node contains an integer value.

    Find the number of paths that sum to a given value.

    The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

    The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

    Example:

    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

          10
         /  \
        5   -3
       / \    \
      3   2   11
     / \   \
    3  -2   1

    Return 3. The paths that sum to 8 are:

    1.  5 -> 3
    2.  5 -> 2 -> 1
    3. -3 -> 11
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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        countPathSum(root, sum, count);
        return count;
    }
    
private:
    vector<int> countPathSum(TreeNode *root, int sum, int &count)
    {
        if(root == NULL)
            return vector<int>();
        
        count += int(root->val == sum);
        if(root->left == NULL && root->right == NULL)
        {
            return vector<int>(1, root->val);
        }
        
        vector<int> localPathSums(1, root->val);
        
        vector<int> leftPathSums = countPathSum(root->left, sum, count);
        vector<int> rightPathSums = countPathSum(root->right, sum, count);
        
        for(int i = 0; i < leftPathSums.size(); ++i)
        {
            count += int(leftPathSums[i] + root->val == sum);
            localPathSums.push_back(leftPathSums[i] + root->val);
        }
        
        
        for(int i = 0; i < rightPathSums.size(); ++i)
        {
            count += int(rightPathSums[i] + root->val == sum);
            localPathSums.push_back(rightPathSums[i] + root->val);
        }
        
        return localPathSums;
    }
};
