ListNode* deleteDuplicates(ListNode* head) {
	ListNode *rHead = new ListNode(INT_MIN);
	if(head == NULL)
		return NULL;

	ListNode *cur = rHead;
	for(ListNode *p_cur = head; p_cur != NULL;)
	{
		cur->next = new ListNode(p_cur->val);
		cur = cur->next;
		ListNode *p_next = p_cur;
		for(; p_next != NULL && p_cur->val == p_next->val; p_next = p_next->next) {}
		p_cur = p_next;
	}

	return rHead->next;
}
