/*
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
	    3
	   / \
	  9  20
	    /  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
*/ 

vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> levelValues;
        
        if(root == NULL)
            return levelValues;
        
        queue<TreeNode *> queueForTree;
        queueForTree.push(NULL);
        queueForTree.push(root);
        
        for(int curLevel = -1; ;)
        {
            TreeNode *curNode = queueForTree.front();
            queueForTree.pop();
            
            if(curNode == NULL)
            {
                if(queueForTree.empty())
                    break;

                levelValues.push_back(vector<int>());
                ++curLevel;
                queueForTree.push(NULL);
            }
            else
            {
                levelValues[curLevel].push_back(curNode->val);
                if(curNode->left)
                    queueForTree.push(curNode->left);
                    
                if(curNode->right)
                    queueForTree.push(curNode->right);
            }
        }
        
        return levelValues;
    }
