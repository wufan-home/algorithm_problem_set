/*
    Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

    Example:
    Given binary tree 
              1
             / \
            2   3
           / \     
          4   5    
    Returns [4, 5, 3], [2], [1].

    Explanation:
    1. Removing the leaves [4, 5, 3] would result in this tree:

              1
             / 
            2          
    2. Now removing the leaf [2] would result in this tree:

              1          
    3. Now removing the leaf [1] would result in the empty tree:

              []         
    Returns [4, 5, 3], [2], [1].

    Credits:
    Special thanks to @elmirap for adding this problem and creating all test cases.
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        if(root == NULL)
            return leaves;
        
        TreeNode *preRoot = new TreeNode(INT_MIN);
        unordered_map<TreeNode *, pair<int, TreeNode *>> childToParentMap;
        childToParentMap[root] = make_pair(int(root->left != NULL) + int(root->right != NULL), preRoot);
        queue<TreeNode *> queueForLeaves;
        queue<TreeNode *> queueForTreeNodes;
        queueForLeaves.push(NULL);
        queueForTreeNodes.push(root);
        while(!queueForTreeNodes.empty())
        {
            TreeNode *cur = queueForTreeNodes.front();
            queueForTreeNodes.pop();
            
            TreeNode *left = cur->left;
            if(left)
            {
                int amountChildren = int(left->left != NULL) + int(left->right != NULL);
                childToParentMap[left] = make_pair(amountChildren, cur);
                queueForTreeNodes.push(left);
            }

            TreeNode *right = cur->right;
            if(right)
            {
                int amountChildren = int(right->left != NULL) + int(right->right != NULL);
                childToParentMap[right] = make_pair(amountChildren, cur);
                queueForTreeNodes.push(right);
            }
            
            if(left == NULL && right == NULL)
                queueForLeaves.push(cur);
        }

        while(1)
        {
            TreeNode *cur = queueForLeaves.front();
            queueForLeaves.pop();
            if(cur == NULL)
            {
                if(queueForLeaves.empty())
                    break;

                leaves.push_back(vector<int>());
                queueForLeaves.push(NULL);
                continue;
            }
            
            leaves[leaves.size() - 1].push_back(cur->val);
            TreeNode *parent = childToParentMap[cur].second;
            if(parent == preRoot)
                break;

            if(--childToParentMap[parent].first == 0)
                queueForLeaves.push(parent);
        }
        
        return leaves;
    }
};
