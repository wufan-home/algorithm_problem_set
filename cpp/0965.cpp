/*
    A binary tree is univalued if every node in the tree has the same value.

    Return true if and only if the given tree is univalued.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        return getUnivalStatus(root, value);
    }
    
private:
    bool getUnivalStatus(TreeNode* root, int value) {
        if (root->val != value || (root->left && !getUnivalStatus(root->left, value)) || (root->right && !getUnivalStatus(root->right, value))) {
            return false;
        }
        
        return true;
    }
};
