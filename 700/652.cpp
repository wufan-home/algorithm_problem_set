/*
    Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, 
    you only need to return the root node of any one of them.

    Two trees are duplicate if they have the same structure with same node values.

    Example 1: 
            1
           / \
          2   3
         /   / \
        4   2   4
           /
          4
    The following are two duplicate subtrees:
          2
         /
        4
    and
        4
    Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL)
            return vector<TreeNode *>();
        
        unordered_map<string, TreeNode *> m;
        
        getValueString(root, m);
        
        vector<TreeNode *> res;
        for(auto a : m)
        {
            if(a.second != NULL)
                res.push_back(a.second);
        }
        return res;
    }
    
private:
    string getValueString(TreeNode *root, unordered_map<string, TreeNode *> &m)
    {
        string key;
        key.append(root->left == NULL ? "" : getValueString(root->left, m) + "L");
        key.append(to_string(root->val));
        key.append(root->right == NULL ? "" : "R" + getValueString(root->right, m));
        
        if(m.find(key) == m.end())
            m[key] = NULL;
        else
            m[key] = root;
        
        return key;
    }
};
