/*
    Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

    Note:
    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {
        double diff = pow(0.1, 10);
        int solution;
        double globalError = -1.0;
        for(TreeNode *cur = root; cur != NULL;)
        {
            double error = cur->val > target ? cur->val - target : target - cur->val;
            if(globalError == -1.0 || error < globalError)
            {
                solution = cur->val;
                globalError = error;
            }
            
            if(error <= diff)
                break;
            else if(cur->val > target)
                cur = cur->left;
            else
                cur = cur->right;
        }
        
        return solution;
    }
};
