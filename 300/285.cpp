/*
    Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

    Note: If the given node has no in-order successor in the tree, return null.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *successor = NULL;
        
        stack<TreeNode *> stackForTreeTraversal;
        TreeNode *cur = root;
        bool meetGivenNode = false;
        while(cur || !stackForTreeTraversal.empty())
        {
            if(cur)
            {
                stackForTreeTraversal.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stackForTreeTraversal.top();
                stackForTreeTraversal.pop();
                if(meetGivenNode)
                {
                    successor = cur;
                    break;
                }
                
                meetGivenNode = (cur == p);
                cur = cur->right;
            }
        }
        
        return successor;
    }
};
