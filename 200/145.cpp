/*

*/

void transverseTreePostOrder(TreeNode *root, vector<int>& results)
    {
        if(root != NULL)
        {
            transverseTreePostOrder(root->left, results);
            transverseTreePostOrder(root->right, results);
            results.push_back(root->val);
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        
        transverseTreePostOrder(root, results);
        return results;
    }
    
    //============================
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        
        stack<TreeNode *> stackForTree;
        TreeNode *curNode = root;
        bool finishedCheckingRightSubtree = false;
        while(curNode != NULL || !stackForTree.empty())
        {
            if(curNode)
            {
                stackForTree.push(curNode);
                curNode = curNode->left;
            }
            else if(!finishedCheckingRightSubtree)
            {
                curNode = stackForTree.top()->right;
                finishedCheckingRightSubtree = (curNode == NULL);
            }
            else
            {
                curNode = stackForTree.top();
                stackForTree.pop();
                results.push_back(curNode->val);
                finishedCheckingRightSubtree = (!stackForTree.empty() && curNode == stackForTree.top()->right);
                curNode = NULL;
            }
        }
        
        return results;
    }
    
