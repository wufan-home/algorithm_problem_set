/*
    Given a non-empty binary search tree and a target value, 
    find k values in the BST that are closest to the target.

    Note:
    Given target value is a floating point.
    You may assume k is always valid, that is: k ≤ total nodes.
    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
    Follow up:
    Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        
        double leftDiff = 0;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur != NULL || !st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                
                double diff = fabs(target - (double)cur->val);
                
                if(res.size() < k)
                {
                    res.push_back(cur->val);
                    leftDiff = fabs(target - (double)res[0]);
                }
                else if(diff > leftDiff)
                    break;
                else
                {
                    res.erase(res.begin());
                    res.push_back(cur->val);
                    leftDiff = fabs(target - (double)res[0]);
                }
                
                cur = cur->right;
            }
        }
        
        return res;
    }
};
