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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        for (int level = q.size(); !q.empty();) {
            Node* cur = q.front();
            q.pop();
            
            if (--level > 0) {
                cur->next = q.front();
            }
            
            if (cur->left) {
                q.push(cur->left);
            }
            
            if (cur->right) {
                q.push(cur->right);
            }
            
            if (level == 0) {
                level = q.size();
            }
        }
        return root;
    }
};
