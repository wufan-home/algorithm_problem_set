/*
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
  Note: Do not modify the linked list.
  Follow up:
  Can you solve it without using extra space?
*/

ListNode *detectCycle(ListNode *head) {
	if(head == NULL)
		return NULL;

	ListNode *slow = head;
	ListNode *fast = head;
	do
	{
		slow = slow->next;
		fast = fast->next;
		if(fast)
			fast = fast->next;
	}while(slow && fast && slow != fast);

	if(fast == NULL && slow == NULL)
		return NULL;

	fast = head;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
}
