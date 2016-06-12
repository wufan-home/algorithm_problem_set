/*
  Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/

void flatten(TreeNode* root) {
        if(root == NULL)
		return;

	TreeNode *right = root->right;
	root->right = root->left;
	root->left = NULL;
	TreeNode *cur = root;
	for(; cur->right; cur = cur->right) {}
	cur->right = right;
	flatten(root->right);
}
