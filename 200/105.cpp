/*
  Given preorder and inorder traversal of a tree, construct the binary tree.
  Note:
  You may assume that duplicates do not exist in the tree.

  Solution:
  Recursive method: The first element of every sub-array is the value of the root of the sub-tree.
  Since the value of every node is not same, find the left and right parts from the inorder array
  which is seperated by the value.

  From this method, we know that the in-order array is used to describe the left sub-tree and
  the right sub-tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return getTreeBuilt(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode *getTreeBuilt(vector<int>& preorder, int startpr, int endpr,
                            vector<int>& inorder, int startin, int endin)
    {
        if(startin > endin)
            return NULL;

        int rootValue = preorder[startpr];
        int indexInorder = startin;
        for(; indexInorder <= endin && inorder[indexInorder] != rootValue; ++indexInorder) {}
        
        TreeNode *root = new TreeNode(rootValue);
        
        int leftSize = indexInorder - startin;
        root->left = getTreeBuilt(preorder, startpr + 1, startpr + leftSize, inorder, startin, indexInorder - 1);
        
        int rightSize = endin - indexInorder;
        root->right = getTreeBuilt(preorder, startpr + leftSize + 1, endpr, inorder, indexInorder + 1, endin);
        
        return root;
    }
};
