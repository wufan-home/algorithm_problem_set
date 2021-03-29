/*
	Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
	    3
	   / \
	  9  20
	    /  \
	   15   7
	return its zigzag level order traversal as:
	[
	  [3],
	  [20,9],
	  [15,7]
	]
*/


vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> levelValuesZigzag;
        
        if(root == NULL)
            return levelValuesZigzag;
            
        queue<TreeNode *> queueForTree;
        queueForTree.push(NULL);
        queueForTree.push(root);
        bool forwardPushValue = false;
        
        for(int curLevel = -1; ; )
        {
            const TreeNode *curNode = queueForTree.front();
            queueForTree.pop();
            
            if(curNode == NULL)
            {
                if(queueForTree.empty())
                    break;
                    
                levelValuesZigzag.push_back(vector<int>());
                ++curLevel;
                forwardPushValue = !forwardPushValue;
                queueForTree.push(NULL);
            }
            else
            {
                if(forwardPushValue)
                    levelValuesZigzag[curLevel].push_back(curNode->val);
                else
                    levelValuesZigzag[curLevel].insert(levelValuesZigzag[curLevel].begin(), 1, curNode->val);
                    
                if(curNode->left)
                    queueForTree.push(curNode->left);
                    
                if(curNode->right)
                    queueForTree.push(curNode->right);
            }
        }
        
        return levelValuesZigzag;
    }
