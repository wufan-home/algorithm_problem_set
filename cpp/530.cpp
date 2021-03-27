/*
    Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
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
    int getMinimumDifference(TreeNode* root) {
        int minDifference = INT_MAX;
        int lastValue = INT_MIN;
        stack<TreeNode *> stackForNode;
        TreeNode *curNode = root;
        while(curNode || !stackForNode.empty())
        {
            if(curNode)
            {
                stackForNode.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                curNode = stackForNode.top();
                stackForNode.pop();
                if(lastValue != INT_MIN)
                    minDifference = min(minDifference, curNode->val - lastValue);
                lastValue = curNode->val;
                curNode = curNode->right;
            }
        }
        
        return minDifference;
    }
};
