/*
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
  You may not alter the values in the nodes, only nodes itself may be changed.
  Only constant memory is allowed.
  For example,
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
*/

ListNode* reverseKGroup(ListNode* head, int k)
{
        if(head == NULL || k == 0)
            return head;

        int count = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next, ++count) {}
        if(k > count)
            return head;

        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *tail = dummy;
        while(head != NULL)
        {
		ListNode *cur = head;
		int i = 0;
		for(; i < k && head != NULL; ++i, head = head->next) {}

		if(i < k)
			tail->next = cur;
		else
		{
			ListNode *start = tail;
			tail = cur; // The local head of the old list is the tail of the new list.
			while(cur != head)
			{
				ListNode *temp = start->next;
				start->next = cur;
				cur = cur->next;
				start->next->next = temp;
			}
		}
        }
        return dummy->next;
}
