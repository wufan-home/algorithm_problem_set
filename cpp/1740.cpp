/*
    Given the root of a binary tree and two integers p and q, return the distance between the nodes of value p and value q in the tree.

    The distance between two nodes is the number of edges on the path from one to the other.



    Example 1:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
    Output: 3
    Explanation: There are 3 edges between 5 and 0: 5-3-1-0.

    Example 2:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
    Output: 2
    Explanation: There are 2 edges between 5 and 7: 5-2-7.

    Example 3:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
    Output: 0
    Explanation: The distance between a node and itself is 0.



    Constraints:

        The number of nodes in the tree is in the range [1, 104].
        0 <= Node.val <= 109
        All Node.val are unique.
        p and q are values in the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        vector<TreeNode*> path1;
        findPath(root, p, path1);
        
        vector<TreeNode*> path2;
        findPath(root, q, path2);
        
        int bound = min(path1.size(), path2.size());
        int local = 0;
        for (; local < bound && path1[local]->val == path2[local]->val; ++local) {}
        return (path1.size() - 1) + (path2.size() - 1) - 2 * (--local);
    }
    
private:
    void findPath(TreeNode* root, int p, vector<TreeNode*>& path) {
        if (root == NULL) {
            return;
        }
        
        path.push_back(root);
        
        findPath(root->left, p, path);
        if (path.back()->val == p) {
            return;
        }
        
        findPath(root->right, p, path);
        if (path.back()->val == p) {
            return;
        }
        
        path.pop_back();
    }
};
