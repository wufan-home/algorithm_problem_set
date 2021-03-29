/*
    Given a complete binary tree, count the number of nodes.

    Definition of a complete binary tree from Wikipedia:
    In a complete binary tree every level, except possibly the last, 
    is completely filled, and all nodes in the last level are as far left as possible. 
    It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            depth++;
            node = node->left;
        }
        if (depth == 0) {
            return 0;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (1 << (depth - 1)) + right;
    }
    TreeNode* getNode(TreeNode* root, int path, int depth) {
        while (depth-- && root) {
            if (path & (1 << depth)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};
