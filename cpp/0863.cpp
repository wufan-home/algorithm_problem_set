/*
    https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
    
    We are given a binary tree (with root node root), a target node, and an integer value K.

    Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.



    Example 1:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

    Output: [7,4,1]

    Explanation: 
    The nodes that are a distance 2 from the target node (with value 5)
    have values 7, 4, and 1.



    Note that the inputs "root" and "target" are actually TreeNodes.
    The descriptions of the inputs above are just serializations of these objects.



    Note:

        The given tree is non-empty.
        Each node in the tree has unique values 0 <= node.val <= 500.
        The target node is a node in the tree.
        0 <= K <= 1000.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        
        populateChildren(target, K, res);
        
        // Find the path to the target
        TreeNode *cur = root;
        stack<TreeNode *> path;
        getPathToTarget(root, target, path);
        
        while (!path.empty() && K >= 0) {
            cur = path.top();
            path.pop();
            
            if (!path.empty()) {
                if (K == 1) {
                    res.push_back(path.top()->val);
                    break;
                }
                
                TreeNode *next = (cur == path.top()->left ? path.top()->right : path.top()->left);
                populateChildren(next, K - 2, res);
            }
            
            --K;
        }
        
        return res;
    }
    
private:
    void populateChildren(TreeNode *root, int length, vector<int> &res) {
        queue<TreeNode *> q;
        
        q.push(root);
        q.push(NULL);
        while (!q.empty() && length >= 0) {
            TreeNode *cur = q.front();
            q.pop();
            
            if (cur == NULL) {
                --length;
                q.push(NULL);
                continue;
            }
            
            if (length == 0) {
                res.push_back(cur->val);
                continue;
            }
            
            if (cur->left != NULL) {
                q.push(cur->left);
            }
            
            if (cur->right != NULL) {
                q.push(cur->right);
            }
        }
    }
    
    void getPathToTarget(TreeNode *root, TreeNode *target, stack<TreeNode *> &path) {
        if (root == NULL || (!path.empty() && path.top() == target)) {
            return;
        } 
        
        if (root == target) {
            path.push(root);
            return;
        }
        
        path.push(root);
                
        getPathToTarget(root->left, target, path);
        if (path.top() == target) {
            return;
        }
        
        getPathToTarget(root->right, target, path);
        if (path.top() == target) {
            return;
        }
        
        path.pop();
    }
};
