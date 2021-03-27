/*
    Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
    where largest means subtree with largest number of nodes in it.

    Note:
    A subtree must include all of its descendants.
    Here's an example:
        10
        / \
       5  15
      / \   \ 
     1   8   7
    The Largest BST Subtree in this case is the highlighted one. 
    The return value is the subtree's size, which is 3.
    Follow up:
    Can you figure out ways to solve it with O(n) time complexity?
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
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int subtreeSize = 0;
        int maxValue = INT_MIN;
        int minValue = INT_MIN;
        verifyBsSubtree(root, minValue, maxValue, subtreeSize);
        
        return subtreeSize;
    }
    
private:
    bool verifyBsSubtree(TreeNode *root, int& mi, int& ma, int& size)
    {
        if(root->left == NULL && root->right == NULL)
        {
            mi = ma = root->val;
            size = 1;
            return true;
        }
        
        int lmi = INT_MAX;
        int lma = INT_MIN;
        int lsize = 0;
        bool islbst = true;
        if(root->left != NULL)
            islbst = verifyBsSubtree(root->left, lmi, lma, lsize);
        
        int rmi = INT_MAX;
        int rma = INT_MIN;
        int rsize = 0;
        bool isrbst = true;
        if(root->right != NULL)
            isrbst = verifyBsSubtree(root->right, rmi, rma, rsize);
        
        if(!islbst || !isrbst || lma >= root->val || rmi <= root->val)
        {
            size = max(lsize, rsize);
            return false;
        }
        
        size = 1;
        if(root->left == NULL)
            mi = root->val;
        else
        {
            mi = lmi;
            size += lsize;
        }
        
        if(root->right == NULL)
            ma = root->val;
        else
        {
            ma = rma;
            size += rsize;
        }
        
        return true;
    }
};
