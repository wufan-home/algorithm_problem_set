/*
  Given a linked list, remove the nth node from the end of list and return its head.
  For example,
  Given linked list: 1->2->3->4->5, and n = 2.
  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(head == NULL)
            return head;
            
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *front = dummy->next;
        for(int i = 0; i < n; ++i, front = front->next) {}
        ListNode *back = dummy;
        while(front)
        {
            back = back->next;
            front = front->next;
        }
        back->next = back->next->next;
        return dummy->next;
}
