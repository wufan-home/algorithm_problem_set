/*
  Merge two sorted linked lists and return it as a new list. 
  The new list should be made by splicing together the nodes of the first two lists.

  Solution: Use a reference to a pointer to avoid the determine which pointer of the list
  should be moved.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while(l1 || l2)
        {
            ListNode *nodeWithSmallerValue = l1 ? (l2 ? (l1->val <= l2->val ? l1 : l2) : l1) : (l2 ? l2 : NULL);
            
            if(nodeWithSmallerValue == l1)
                l1 = l1->next;
            else 
                l2 = l2->next;

            if(head == NULL)
            {
                cur = nodeWithSmallerValue;
                head = cur;
            }
            else
            {
                cur->next = nodeWithSmallerValue;
                cur = cur->next;
            }
            
            cur->next = NULL;
        }
        
        return head;
    }
};
