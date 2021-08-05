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
        vector<TreeNode*> ans;
        unordered_set<int> valueToDelete(to_delete.begin(), to_delete.end());
        aux(root, valueToDelete, ans, true);
        return ans;
    }
    
private:
    TreeNode* aux(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& ans, bool isRoot) {
        if (root == NULL) {
            return NULL;
        }
        
        // This is the critical step:
        // Only the not deleted root has to be in the result list.
        // If the parent is not deleted (no matter it is root), its child needs not to be in the ans.
        // In the meantime, if the current root is to be deleted, all its children may become two new roots.
        bool toDelete = to_delete.count(root->val) > 0;
        if (isRoot && !toDelete) {
            ans.push_back(root);
        }
        
        TreeNode* l = aux(root->left, to_delete, ans, toDelete);
        TreeNode* r = aux(root->right, to_delete, ans, toDelete);
        if (!toDelete) {
            root->left = l;
            root->right = r;
        }
        
        return toDelete ? NULL : root;
    }
};
