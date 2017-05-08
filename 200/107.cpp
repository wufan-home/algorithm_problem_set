/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

  Solution:
  
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
            
        stack<vector<int> *> stackForLevelValues;
        queue<TreeNode *> queueForTreeNode;
        
        queueForTreeNode.push(root);
        queueForTreeNode.push(NULL);
        vector<int> *level = NULL;
        while(!queueForTreeNode.empty())
        {
            TreeNode *cur = queueForTreeNode.front();
            queueForTreeNode.pop();
            if(cur == NULL)
            {
                stackForLevelValues.push(level);
                level = NULL;
                if(!queueForTreeNode.empty())
                    queueForTreeNode.push(NULL);
            }
            else
            {
                if(level == NULL)
                    level = new vector<int>();
                    
                (*level).push_back(cur->val);
                
                if(cur->left)
                    queueForTreeNode.push(cur->left);
                    
                if(cur->right)
                    queueForTreeNode.push(cur->right);
            }
        }
        
        vector<vector<int>> reverseLevels;
        while(!stackForLevelValues.empty())
        {
            reverseLevels.push_back(*(stackForLevelValues.top()));
            stackForLevelValues.pop();
        }
        
        return reverseLevels;
    }
};
