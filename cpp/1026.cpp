/*
    Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

    A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.



    Example 1:

    Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
    Output: 7
    Explanation: We have various ancestor-node differences, some of which are given below :
    |8 - 3| = 5
    |3 - 7| = 4
    |8 - 1| = 7
    |10 - 13| = 3
    Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

    Example 2:

    Input: root = [1,null,2,null,0,3]
    Output: 3



    Constraints:

        The number of nodes in the tree is in the range [2, 5000].
        0 <= Node.val <= 105


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
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return max_diff;
    }
    

private:
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        if (min_.empty() || root->val < min_.top()->val) {
            min_.push(root);
        }
        
        if (max_.empty() || root->val > max_.top()->val) {
            max_.push(root);
        }
            
        if (root->left == NULL && root->right == NULL) {
            // leaf
            max_diff = max(max_diff, max_.top()->val - min_.top()->val);
        }
        
        dfs(root->left);
        dfs(root->right);
        
        if (root == max_.top()) {
            max_.pop();
        }
        
        if (root == min_.top()) {
            min_.pop();
        }
        
    }
    
    int max_diff;
    
    stack<TreeNode*> min_;
    stack<TreeNode*> max_;
};
