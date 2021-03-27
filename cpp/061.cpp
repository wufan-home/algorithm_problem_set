/*
  Given a list, rotate the list to the right by k places, where k is non-negative.
  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL
*/

ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
		return head;

	int size = 0;
	for(ListNode *cur = head; cur != NULL; cur = cur->next)
		++size;

	if(k >= size)
		k %= size;
	if(k == 0)
		return head;

	ListNode *dummy = new ListNode(INT_MIN);
	dummy->next = head;
	ListNode *back = dummy;
	ListNode *front = dummy;
	ListNode *tail = NULL;
	for(int i = 0; i <= k; ++i)
		front = front->next;

	for(; front != NULL; back = back->next, front = front->next)
	{
		if(front->next == NULL)
			tail = front;
	}
	head = back->next;
	tail->next = dummy->next;
	return head;
}
