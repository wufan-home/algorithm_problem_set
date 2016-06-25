/*
  Merge two sorted linked lists and return it as a new list. 
  The new list should be made by splicing together the nodes of the first two lists.

  Solution: Use a reference to a pointer to avoid the determine which pointer of the list
  should be moved.
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(INT_MIN);
        for(ListNode *cur = dummy; l1 || l2;)
        {
            ListNode* &moving = ((l1 ? l1->val : INT_MAX) <= (l2 ? l2->val : INT_MAX)) ? l1 : l2;
            cur->next = moving;
            moving = moving->next;
            cur = cur->next;
        }
        return dummy->next;
}
