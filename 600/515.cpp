/*
    You need to find the largest value in each row of a binary tree.

    Example:
    Input: 

              1
             / \
            3   2
           / \   \  
          5   3   9 

    Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxValues;
        if(root == NULL)
            return maxValues;
        
        queue<TreeNode *> q;
        q.push(NULL);
        q.push(root);
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur == NULL && !q.empty())
            {
                maxValues.push_back(INT_MIN);
                q.push(NULL);
            }
            else if(cur != NULL)
            {
                maxValues[maxValues.size() - 1] = max(maxValues[maxValues.size() - 1], cur->val);
                if(cur->left)
                    q.push(cur->left);

                if(cur->right)
                    q.push(cur->right);
            }
        }
        
        return maxValues;
    }
};
