/*
  Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

    Solution: This problem cannnot be solved by the recursive method, since its structure is not symmetric.
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
            
        vector<TreeLinkNode *> vectorForTreeTrasversal;
        vectorForTreeTrasversal.push_back(root);
        for(int start = 0, end = 0; start < vectorForTreeTrasversal.size(); end = vectorForTreeTrasversal.size() - 1)
        {
            int i = start;
            start = end + 1;
            for(; i <= end; ++i)
            {
                TreeLinkNode *neighbour = NULL;
                for(int j = i + 1; j <= end; ++j)
                {
                    TreeLinkNode *node = vectorForTreeTrasversal[j];
                    neighbour = node->left ? node->left : (node->right ? node->right : NULL);
                    if(neighbour)
                        break;
                }
                
                if(vectorForTreeTrasversal[i]->left)
                {
                    vectorForTreeTrasversal[i]->left->next = vectorForTreeTrasversal[i]->right ? 
                                                             vectorForTreeTrasversal[i]->right : 
                                                             neighbour;
                    vectorForTreeTrasversal.push_back(vectorForTreeTrasversal[i]->left);
                }
                    
                if(vectorForTreeTrasversal[i]->right)
                {
                    vectorForTreeTrasversal[i]->right->next = neighbour;
                    vectorForTreeTrasversal.push_back(vectorForTreeTrasversal[i]->right);
                }
            }
        }
    }
};
