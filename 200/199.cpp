/*
    Given a binary tree, imagine yourself standing on the right side of it, 
    return the values of the nodes you can see ordered from top to bottom.

    For example:
    Given the following binary tree,
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
    You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(root == NULL)
            return view;
        
        queue<TreeNode *> q;
        q.push(NULL);
        q.push(root);
        int size = -1;
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur == NULL)
            {
                if(!q.empty())
                {
                    view.push_back(INT_MIN);
                    ++size;
                    q.push(NULL);
                }
                
                continue;
            }
            
            view[size] = cur->val;
            
            if(cur->left)
                q.push(cur->left);
            
            if(cur->right)
                q.push(cur->right);
        }
        
        return view;
    }
};
