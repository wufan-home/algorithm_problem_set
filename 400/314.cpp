/*
    Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

    If two nodes are in the same row and column, the order should be from left to right.

    Examples:

    Given binary tree [3,9,20,null,null,15,7],
       3
      /\
     /  \
     9  20
        /\
       /  \
      15   7
    return its vertical order traversal as:
    [
      [9],
      [3,15],
      [20],
      [7]
    ]
    Given binary tree [3,9,8,4,0,1,7],
         3
        /\
       /  \
       9   8
      /\  /\
     /  \/  \
     4  01   7
    return its vertical order traversal as:
    [
      [4],
      [9],
      [3,0,1],
      [8],
      [7]
    ]
    Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
         3
        /\
       /  \
       9   8
      /\  /\
     /  \/  \
     4  01   7
        /\
       /  \
       5   2
    return its vertical order traversal as:
    [
      [4],
      [9,5],
      [3,0,1],
      [8,2],
      [7]
    ]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL)
            return vector<vector<int>>();
        
        map<int, vector<int>> indexToValues;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            TreeNode *cur = q.front().first;
            int index = q.front().second;
            
            q.pop();
            if(indexToValues.find(index) == indexToValues.end())
                indexToValues[index] = vector<int>();
            
            indexToValues[index].push_back(cur->val);
            
            if(cur->left)
                q.push(make_pair(cur->left, index - 1));
            
            if(cur->right)
                q.push(make_pair(cur->right, index + 1));
        }
        
        vector<vector<int>> res;
        for(auto entry : indexToValues)
            res.push_back(entry.second);
        
        return res;
    }
};
