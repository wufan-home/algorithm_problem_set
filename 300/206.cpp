/*
  Reverse a singly linked list.
  A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

ListNode* reverseList(ListNode* head) {
        ListNode *reverse = new ListNode(INT_MIN);
        while(head)
        {
            ListNode *temp = reverse->next;
            reverse->next = head;
            head = head->next;
            reverse->next->next = temp;
        }
        return reverse->next;
}

ListNode *Reverse(ListNode *head, ListNode* &tail)
{
    	if(head == NULL)
    		return NULL;
    
    	ListNode *temp = head;
    	head = head->next;
    	temp->next = NULL;
    	ListNode *reverse = Reverse(head, tail);
    	if(reverse == NULL)
    	{
    	    reverse = temp;
    	    tail = temp;
    	}
    	else
    	{
    	    tail->next = temp;
    		tail = tail->next;
    	}

    	return reverse;
}
    
ListNode* reverseList(ListNode* head)
{
    	if(head == NULL)
    		return NULL;
    
        ListNode *tail = NULL;
    	return Reverse(head, tail);
}
