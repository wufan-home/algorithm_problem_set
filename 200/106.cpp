/*
  Given inorder and postorder traversal of a tree, construct the binary tree.
  Note:
  You may assume that duplicates do not exist in the tree.

  Solution:
  Similar with the problem 105.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        
        return getTreeBuilt(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
private:
    TreeNode *getTreeBuilt(const vector<int>& inorder, int startin, int endin,
                            const vector<int>& postorder, int startpost, int endpost)
    {
        if(startin > endin)
            return NULL;

        int rootValue = postorder[endpost];
        int indexInorder = startin;
        for(; indexInorder <= endin && inorder[indexInorder] != rootValue; ++indexInorder) {}
        
        
        TreeNode *root = new TreeNode(rootValue);
        
        int leftSize = indexInorder - startin;
        root->left = getTreeBuilt(inorder, startin, indexInorder - 1, postorder, startpost, startpost + leftSize - 1);
        
        int rightSize = endin - indexInorder - 1;
        root->right = getTreeBuilt(inorder, indexInorder + 1, endin, postorder, startpost + leftSize, endpost - 1);
        
        return root;
        
    }
};
