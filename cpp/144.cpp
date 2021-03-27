/*
  Given a binary tree, return the preorder traversal of its nodes' values.
  For example:
  Given binary tree {1,#,2,3},
     1
      \
       2
      /
     3
  return [1,2,3].
*/

void transverseTreePreOrder(TreeNode *root, vector<int>& results)
{
    if(root != NULL)
    {
        results.push_back(root->val);
        transverseTreePreOrder(root->left, results);
        transverseTreePreOrder(root->right, results);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    // Recursive: Pre-order.
    vector<int> results;
    transverseTreePreOrder(root, results);
    return results;
}

// ============

vector<int> preorderTraversal(TreeNode* root) {
        // Pre-order.
        vector<int> results;
        
        stack<TreeNode *> stackForTree;
        TreeNode *curNode = root;
        while(curNode != NULL || !stackForTree.empty())
        {
            if(curNode)
            {
                results.push_back(curNode->val);
                stackForTree.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                curNode = stackForTree.top();
                stackForTree.pop();
                curNode = curNode->right;
            }
        }
        
        return results;
    }
