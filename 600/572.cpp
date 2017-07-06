/*
    Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

    Example 1:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
    Given tree t:
       4 
      / \
     1   2
    Return true, because t has the same structure and node values with a subtree of s.
    Example 2:
    Given tree s:

         3
        / \
       4   5
      / \
     1   2
        /
       0
    Given tree t:
       4
      / \
     1   2
    Return false.
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
    Solution() : foundSubtree(false) {}
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL)
            return s == NULL;
        
        if(s == NULL)
            return false;
        
        checkSubtree(s, t);
        
        return foundSubtree;
    }
    
private:
    void checkSubtree(TreeNode *s, TreeNode *t)
    {
        if(foundSubtree)
            return;
        
        if(s == NULL)
            return;
        
        if(s->val == t->val)
            foundSubtree = isSameTree(s, t);
        
        checkSubtree(s->left, t);
        checkSubtree(s->right, t);
    }
    
    bool isSameTree(TreeNode *t1, TreeNode *t2)
    {
        return (t1 == NULL && t2 == NULL) ||
            (t1 != NULL && t2 != NULL && t1->val == t2->val && 
             isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
    }
    
    bool foundSubtree;
};
