/*
  Invert a binary tree.

         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    to
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
    Trivia:
    This problem was inspired by this original tweet by Max Howell:
    Google: 90% of our engineers use the software you wrote (Homebrew), 
    but you can’t invert a binary tree on a whiteboard so fuck off.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)    return root;
        TreeNode* p_left_subtree_root = invertTree(root->left);
        TreeNode* p_right_subtree_root = invertTree(root->right);
        root->left = p_right_subtree_root;
        root->right = p_left_subtree_root;
        return root;
    }
};
