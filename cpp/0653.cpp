/*
    Given a Binary Search Tree and a target number, 
    return true if there exist two elements in the BST such that their sum is equal to the given target.

    Example 1:
    Input: 
        5
       / \
      3   6
     / \   \
    2   4   7

    Target = 9

    Output: True
    Example 2:
    Input: 
        5
       / \
      3   6
     / \   \
    2   4   7

    Target = 28

    Output: False
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                
                int value = k - cur->val;
                if(search(root, value, cur))
                    return true;
                
                cur = cur->right;
            }
        }
        
        return false;
    }
    
private:
    bool search(TreeNode *root, int value, TreeNode *cur)
    {
        while(root != NULL)
        {
            if(value == root->val && root != cur)
                return true;
            else if(value < root->val)
                root = root->left;
            else
                root = root->right;
        }
        
        return false;
    }
};
