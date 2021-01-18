/*
    Given the root of a binary tree, each node in the tree has a distinct value.

    After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

    Return the roots of the trees in the remaining forest.  You may return the result in any order.



    Example 1:

    Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
    Output: [[1,2,null,4],[6],[7]]



    Constraints:

        The number of nodes in the given tree is at most 1000.
        Each node has a distinct value between 1 and 1000.
        to_delete.length <= 1000
        to_delete contains distinct values between 1 and 1000.


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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> cache;
        for (int i = 0; i < to_delete.size(); ++i) {
            cache.insert(to_delete[i]);
        }
        
        vector<TreeNode*> forest;
        root = removeNodes(root, cache, forest);
        
        if (root != NULL) {
            forest.push_back(root);
        }
        
        return forest;
    }
    
private:
    TreeNode* removeNodes(TreeNode *root, unordered_set<int>& cache, vector<TreeNode*>& forest) {
        int value = root->val;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        bool to_delete = (cache.count(root->val) != 0);
        
        if (to_delete) {
            root->left = NULL;
            root->right = NULL;
        }
        
        if (l != NULL) {
            l = removeNodes(l, cache, forest);
        }
        
        if (r != NULL) {
            r = removeNodes(r, cache, forest);
        }
        
        if (to_delete) {
            if (l != NULL) {
                forest.push_back(l);
            }
            
            if (r != NULL) {
                forest.push_back(r);
            }
        }
        else {
            root->left = l;
            root->right = r;
        }
        
        return to_delete ? NULL : root;
    }
};
