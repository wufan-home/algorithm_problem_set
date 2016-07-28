/*
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
  You must do this in-place without altering the nodes' values.
  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

void reorderList(ListNode *head) {
        int count = 0;
        for(ListNode *cur = head; cur ; cur = cur->next, ++count) {}
        if(count == 0)
		return;
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *ptrs[2] = {dummy, dummy};
        for(int i = 0; i < count / 2; ++i, ptrs[1] = ptrs[1]->next) {}
        
        ListNode *temp = ptrs[1]->next;
        ptrs[1]->next = NULL;
        ptrs[1] = temp;
        
        ListNode *reverse = new ListNode(INT_MIN);
        ListNode *rcur = reverse;
        while(ptrs[1])
        {
		ListNode *temp = reverse->next;
		reverse->next = ptrs[1];
		ptrs[1] = ptrs[1]->next;
		reverse->next->next = temp;
        }
        ptrs[1] = reverse;
        
        ptrs[0] = ptrs[0]->next;
        ptrs[1] = ptrs[1]->next;
        ListNode *result = new ListNode(INT_MIN);
        ListNode *cur = result;
        for(int i = 0; ptrs[0] || ptrs[1]; ++i)
        {
		cur->next = ptrs[i % 2];
		if(ptrs[i % 2])
		{
			ptrs[i % 2] = ptrs[i % 2]->next;
			cur = cur->next;
		}
        }
        
        head = result->next;
}
