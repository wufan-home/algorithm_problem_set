/*
    Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

    The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, 
    create two tree nodes with value v as N's left subtree root and right subtree root. 
    And N's original left subtree should be the left subtree of the new left subtree root, 
    its original right subtree should be the right subtree of the new right subtree root. 
    If depth d is 1 that means there is no depth d-1 at all, 
    then create a tree node with value v as the new root of the whole original tree, 
    and the original tree is the new root's left subtree.

    Example 1:
    Input: 
    A binary tree as following:
           4
         /   \
        2     6
       / \   / 
      3   1 5   

    v = 1

    d = 2

    Output: 
           4
          / \
         1   1
        /     \
       2       6
      / \     / 
     3   1   5   

    Example 2:
    Input: 
    A binary tree as following:
          4
         /   
        2    
       / \   
      3   1    

    v = 1

    d = 3

    Output: 
          4
         /   
        2
       / \    
      1   1
     /     \  
    3       1
    Note:
    The given d is in range [1, maximum depth of the given tree + 1].
    The given binary tree has at least one tree node.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        stack<TreeNode *> stackForTreeTraversal;
        TreeNode *cur = root;
        bool isBackFromRightChild = false;
        while(cur || !stackForTreeTraversal.empty())
        {
            if(cur)
            {
                //cout << cur->val << ", " << stackForTreeTraversal.size() << endl;
                if(stackForTreeTraversal.size() == d - 2)
                {
                    addOneLevelToNode(cur, v);
                    if(stackForTreeTraversal.empty())
                        break;
                    else if(cur == stackForTreeTraversal.top()->left)
                    {
                        cur = stackForTreeTraversal.top()->right;
                        isBackFromRightChild = (cur == NULL);
                    }
                    else
                    {
                        isBackFromRightChild = true;
                        cur = NULL;
                    }
                }
                else
                {
                    stackForTreeTraversal.push(cur);
                    cur = cur->left;
                }
            }
            else if(isBackFromRightChild)
            {
                cur = stackForTreeTraversal.top();
                stackForTreeTraversal.pop();
                isBackFromRightChild = (!stackForTreeTraversal.empty() && 
                                        cur == stackForTreeTraversal.top()->right);
                cur = NULL;
            }
            else
            {
                cur = stackForTreeTraversal.top()->right;
                if(cur == NULL)
                    isBackFromRightChild = true;
            }
        }
        
        return root;
    }
    
private:
    void addOneLevelToNode(TreeNode *node, int v)
    {
        cout << "parent = " << node->val << endl;
        TreeNode *tempLeft = node->left;
        node->left = new TreeNode(v);
        node->left->left = tempLeft;
        
        TreeNode *tempRight = node->right;
        node->right = new TreeNode(v);
        node->right->right = tempRight;
    }
};
