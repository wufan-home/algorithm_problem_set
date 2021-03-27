/*
    Given the root of a tree, you are asked to find the most frequent subtree sum. 
    The subtree sum of a node is defined as the sum of all the node values 
    formed by the subtree rooted at that node (including the node itself). 
    So what is the most frequent subtree sum value? If there is a tie, 
    return all the values with the highest frequency in any order.

    Examples 1
    Input:

      5
     /  \
    2   -3
    return [2, -3, 4], since all the values happen only once, return all of them in any order.
    Examples 2
    Input:

      5
     /  \
    2   -5
    return [2], since 2 happens twice, however -5 only occur once.
    Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL)
            return vector<int>();
        
        int value = countSubtreeValueSum(root);
        ++valueFreq[value];
        
        int maxFreq = INT_MIN;
        for(auto a : valueFreq)
            maxFreq = max(maxFreq, a.second);
        
        vector<int> maxValues;
        for(auto a : valueFreq)
        {
            if(a.second == maxFreq)
                maxValues.push_back(a.first);
        }
        
        return maxValues;
    }
private:
    int countSubtreeValueSum(TreeNode *root)
    {
        int left = 0; 
        if(root->left)
        {
            left = countSubtreeValueSum(root->left);
            ++valueFreq[left];
        }
        
        int right = 0; 
        if(root->right)
        {
            right = countSubtreeValueSum(root->right);
            ++valueFreq[right];
        }
        
        return root->val + left + right;
    }
    
    unordered_map<int, int> valueFreq;
};
