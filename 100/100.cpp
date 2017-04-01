/*
  Given two binary trees, write a function to check if they are equal or not.
  Two binary trees are considered equal 
  if they are structurally identical and the nodes have the same value.
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
	// Recursive: DFS.
	// This is the pre-order trasversal.
	return (p == NULL && q == NULL) ||
	    (p != NULL && q != NULL && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	
	// This is the in-order trasversal.
	return (p == NULL && q == NULL) ||
	    (p != NULL && q != NULL && isSameTree(p->left, q->left) && p->val == q->val && isSameTree(p->right, q->right));
	
	// This is the post-order trasversal.
	return (p == NULL && q == NULL) ||
	    (p != NULL && q != NULL && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	//BFS
        queue<TreeNode *> l_queue;
        queue<TreeNode *> r_queue;
        
        l_queue.push(p);
        r_queue.push(q);
            
        while(!l_queue.empty() && !r_queue.empty())
        {
            TreeNode *l_ptr = l_queue.front();
            l_queue.pop();
            
            TreeNode *r_ptr = r_queue.front();
            r_queue.pop();
            
            if(l_ptr == NULL && r_ptr == NULL)
                continue;
            else if(l_ptr == NULL ||
                    r_ptr == NULL ||
                    (l_ptr->val != r_ptr->val))
                return false;

            l_queue.push(l_ptr->left);
            l_queue.push(l_ptr->right);
            r_queue.push(r_ptr->left);
            r_queue.push(r_ptr->right);
        }
        
        return l_queue.empty() && r_queue.empty();
}
