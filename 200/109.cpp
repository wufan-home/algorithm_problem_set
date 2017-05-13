/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next)
            ++size;
            
        return getSubtreeBySize(head, size);
    }
    
private:
    TreeNode* getSubtreeBySize(ListNode *head, int size)
    {
        if(head == NULL) 
            return NULL;
        
        if(head->next == NULL)
            return new TreeNode(head->val);
            
        int leftSize = size / 2;
        ListNode *newHead = head;
        for(int i = 0; i < leftSize - 1; ++i, newHead = newHead->next) {}
        
        TreeNode *root = new TreeNode(newHead->next->val);
        
        ListNode *right = newHead->next->next;
        newHead->next->next = NULL;
        newHead->next = NULL;
        
        root->left = getSubtreeBySize(head, leftSize);
        root->right = getSubtreeBySize(right, size - leftSize - 1);
        return root;
    }
};
